#pragma once
#include "String.h"
class User
{
public:
	User();
	String getName() const;
	void setName(const String&);
	String getPassword() const;
	void setPassword(const String&);
	bool getAdmin() const;
	bool getLoggedIn() const;
	void setLoggedIn(const bool);
	void setAdmin(const bool);
	void loadUser(std::istream&);
	void saveUser(std::ostream&) const;
	bool operator==(const User&);
	User& operator=(const User& other);
private:
	String name;
	String password;
	bool isAdmin;
	bool isLoggedIn;
};