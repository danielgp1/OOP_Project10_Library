#pragma once
#include "User.h"
#include "String.h"
#include "Vector.h"
class UserStore
{
public:
	UserStore();

	const size_t getLinesOfFile(std::ifstream&) const;
	size_t getSize() const;

	void addUser(const String&,const String&);
	void removeUser(const String&);
	void clear();
	
	User& operator[](const size_t) const;
	int activeUserIndex() const;

	void loadUsers(std::ifstream& in);
	void saveUsers(std::ofstream& out);
private:
	Vector<User> users;
	size_t total;
};