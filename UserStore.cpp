#include "UserStore.h"

UserStore::UserStore()
{
	this->total = 0;
}

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
	this->total++;
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
	this->total--;
	std::cout << "User successfully removed!\n";
}


size_t UserStore::getSize() const
{
	return this->users.getSize();
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

const size_t UserStore::getLinesOfFile(std::ifstream& in) const
{
	in.unsetf(std::ios_base::skipws);
	size_t line_count = std::count(
		std::istream_iterator<char>(in),
		std::istream_iterator<char>(),
		'\n');
	return line_count;
}

void UserStore::loadUsers(std::ifstream& in)
{
	in.seekg(0, std::ios::end);
	int size = in.tellg();
	if (size == -1)
	{
		std::cout << "Database can't be empty!\n";
		return;
	}
	in.seekg(0, std::ios::beg);
	size_t total;
	in >> total;
	for (size_t i = 0; i < total; ++i)
	{
		User user;
		user.loadUser(in);
		this->addUser(user.getName(), user.getPassword());
	}
}

void UserStore::saveUsers(std::ofstream& out)
{
	out << this->total << "\n";
	size_t size = users.getSize();
	for (size_t i = 0;i < size; ++i)
	{
		users[i].saveUser(out);
	}
}

void UserStore::clear()
{
	UserStore clean;
	*this = clean;
}