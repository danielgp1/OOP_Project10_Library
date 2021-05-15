#include "UserStore.h"

void UserStore::addUser(const String& username,const String& password)
{
	size_t size = users.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		if (users[i].getName() == username)
		{
			std::cout << "This user already exists!\n";
			return;
		}
	}	
	User newUser;
	newUser.setName(username);
	newUser.setPassword(password);
	if (username == "admin")
	{
		newUser.setAdmin(true);
		newUser.setLoggedIn(true);
	}	
	else
	{
		newUser.setLoggedIn(false);
		newUser.setAdmin(false);
	}
	users.pushBack(newUser);
}

void UserStore::removeUser(const String& username)
{
	size_t size = users.getSize();
	int indexOfUser = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (users[i].getName() == username)
		{
			indexOfUser = i;
			break;
		}
	}
	if (indexOfUser == -1)
	{
		std::cout << "User not found!\n";
		return;
	}
	users.removeAt(indexOfUser);
	std::cout << "User successfully removed!\n";
}

void UserStore::print() const
{
	size_t size = users.getSize();
	std::cout << "Registered users:\n";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << users[i].getName() << " | ";
	}
}

size_t UserStore::getSize() const
{
	return this->users.getSize();
}

Vector<String> UserStore::registeredUsers() const
{
	size_t size = users.getSize();
	Vector<String> registeredUsers;
	for (size_t i = 0; i < size; ++i)
	{
		registeredUsers.pushBack(users[i].getName());
	}
	return registeredUsers;
}

User& UserStore::operator[](const size_t index) const
{
	return this->users[index];
}

int UserStore::activeUserIndex() const
{
	size_t size = users.getSize();
	int index = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (users[i].getLoggedIn() == true)
		{
			index = i;
			break;
		}
	}
	return index;
}

const size_t UserStore::getLinesOfFile(const String& filename)
{
	std::ifstream myfile(filename.getText());
	myfile.unsetf(std::ios_base::skipws);
	size_t line_count = std::count(
		std::istream_iterator<char>(myfile),
		std::istream_iterator<char>(),
		'\n');
	return line_count;
}

void UserStore::loadUsers(const String& filename)
{
	std::ifstream in(filename.getText());
	size_t lines = getLinesOfFile(filename);
	std::ifstream in2(filename.getText(), std::ios::app);
	for (size_t i = 0; i < lines/4; ++i)
	{
		User user;
		user.loadUser(in2);
		this->addUser(user.getName(), user.getPassword());
	}
	std::cout << "Users database successfully loaded!\n";
}

void UserStore::saveUsers(const String& filename)
{
	size_t size = users.getSize();
	std::ofstream out(filename.getText());
	for (size_t i = 0;i < size; ++i)
	{
		users[i].saveUser(out);
	}
}

