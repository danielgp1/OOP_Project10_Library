#include "User.h"

User::User()
{
	this->name = "";
	this->password = "";
	this->isAdmin = 0;
	this->isLoggedIn = 0;
}

User::User(String& _name, String& _pass)
{
	this->name = _name;
	this->password = _pass;
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

void User::loadUser(std::ifstream& in)
{
	in >> name;
	if (name == "\n")
		in >> name;
	in >> password;
	in >> isAdmin;
	in >> isLoggedIn;
}

void User::saveUser(std::ostream& out) const
{
	out << name << "\n";
	out << password << "\n";
	out << isAdmin << "\n";
	out << isLoggedIn << "\n";
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
