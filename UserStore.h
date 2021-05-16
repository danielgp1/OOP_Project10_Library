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
	const size_t getLinesOfFile(std::ifstream&);
	User& operator[](const size_t) const;
	int activeUserIndex() const;
	void loadUsers(std::ifstream& in);
	void saveUsers(std::ofstream& out);
	void clear();
private:
	Vector<User> users;
	size_t total;
};