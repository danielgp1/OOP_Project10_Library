#pragma once
#include "User.h"
#include "String.h"
#include "Vector.h"
class UserStore
{
public:
	UserStore();
	void addUser(const String&,const String&);
	void removeUser(const String&);
	void print() const;
	size_t getSize() const;
	Vector<String> registeredUsers() const;
	User& operator[](const size_t) const;
	int activeUserIndex() const;
	const size_t getLinesOfFile(const String&);
	void loadUsers(std::ifstream& in);
	void saveUsers(std::ofstream& out);
private:
	Vector<User> users;
	size_t total;
};

