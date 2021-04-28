#include "User.h"

User::User()
{
	this->name = "admin";
	this->password = "i<3c++";
	this->isAdmin = 1;
	this->isLoggedIn = 1;
}

String User::getName() const
{
	return this->name;
}

void User::setName(const String& _name)
{
	this->name = _name;
}

String User::getPassword() const
{
	return this->password;
}

void User::setPassword(const String& _password)
{
	this->password = _password;
}

bool User::getAdmin() const
{
	return this->isAdmin;
}

bool User::getLoggedIn() const
{
	return this->isLoggedIn;
}

void User::setLoggedIn(const bool _status)
{
	this->isLoggedIn = _status;
}

void User::setAdmin(const bool _level)
{
	this->isAdmin = _level;
}

bool User::operator==(const User& user)
{
	if (this->name == user.name && this->password == user.password)
		return true;
	return false;
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->password = other.password;
		this->isAdmin = other.isAdmin;
		this->isLoggedIn = other.isLoggedIn;
	}
	return *this;
}
