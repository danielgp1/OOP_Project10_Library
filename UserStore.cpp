#include "UserStore.h"

UserStore::UserStore()
{
	this->size = 0;
	this->capacity = 8;
	this->users = new User[capacity];
}

UserStore::~UserStore()
{
	this->erase();
}

UserStore::UserStore(const UserStore& otherStore)
{
	this->copy(otherStore);
}

UserStore& UserStore::operator=(const UserStore& otherStore)
{
	if (this != &otherStore)
	{
		this->erase();
		this->copy(otherStore);
	}
	return *this;
}

void UserStore::addUser(const String& username,const String& password)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (users[i].getName() == username)
		{
			std::cout << "This user already exists!\n";
			return;
		}
	}	
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	User newUser;
	newUser.setName(username);
	newUser.setPassword(password);
	newUser.setLoggedIn(false);
	newUser.setAdmin(false);
	this->users[size++] = newUser;
}

void UserStore::removeUser(const String& username)
{
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
	for (size_t i = indexOfUser; i < size - 1; ++i)
	{
		users[i] = users[i + 1];
	}
	size--;
}

void UserStore::print() const
{
	std::cout << "Registered users:\n";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << users[i].getName() << " | ";
	}
}

size_t UserStore::getSize() const
{
	return this->size;
}

Vector<String> UserStore::registeredUsers() const
{
	Vector<String> registeredUsers;
	for (size_t i = 0; i < size; ++i)
	{
		registeredUsers.pushBack(users[i].getName());
	}
	return registeredUsers;
}

User& UserStore::operator[](const size_t index)
{
	return this->users[index];
}

int UserStore::activeUserIndex() const
{
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

void UserStore::copy(const UserStore& otherStore)
{
	this->size = otherStore.size;
	this->capacity = otherStore.capacity;
	this->users = new User[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		this->users[i] = otherStore.users[i];
	}
}

void UserStore::erase()
{
	delete[] this->users;
}

void UserStore::resize()
{
	this->capacity *= 2;
	User* temp = new User[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		temp[i] = this->users[i];
	}
	delete[] this->users;
	this->users = temp;
}
