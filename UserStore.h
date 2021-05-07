#pragma once
#include "User.h"
#include "String.h"
#include "Vector.h"
class UserStore
{
public:
	void addUser(const String&,const String&);
	void removeUser(const String&);
	void print() const;
	size_t getSize() const;
	Vector<String> registeredUsers() const;
	User& operator[](const size_t) const;
	int activeUserIndex() const;
private:
	Vector<User> users;
};

