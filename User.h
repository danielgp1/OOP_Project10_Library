#pragma once
#include "String.h"
class User
{
public:
	User();
	User(String&, String&);

	const String& getName() const;
	const String& getPassword() const;
	const bool getAdmin() const;
	const bool getLoggedIn() const;

	void setPassword(const String&);
	void setName(const String&);
	void setLoggedIn(const bool);
	void setAdmin(const bool);

	void loadUser(std::ifstream&);
	void saveUser(std::ostream&) const;

	bool operator==(const User&);
private:
	String name;
	String password;
	bool isAdmin;
	bool isLoggedIn;
};