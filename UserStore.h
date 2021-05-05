#pragma once
#include "User.h"
#include "String.h"
#include "Vector.h"
class UserStore
{
public:
	UserStore();
	~UserStore();
	UserStore(const UserStore&);
	UserStore& operator=(const UserStore&);
	void addUser(const String&,const String&);
	void removeUser(const String&);
	void print() const;
	size_t getSize() const;
	Vector<String> registeredUsers() const;
	User& operator[](const size_t) const;
	int activeUserIndex() const;
private:
	User* users;
	size_t size;
	size_t capacity;
	void copy(const UserStore&);
	void erase();
	void resize();
};

