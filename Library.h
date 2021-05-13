#pragma once
#include "UserStore.h"
#include "BookStore.h"
class Library
{
public:
	Library();
	void open(const char*);
	void save(const char*);
	void saveAs(const char*);
	void close();
	void logIn();
	void logOut();
	void help() const;
	void booksAll()const;
	void booksInfo(size_t) const;
	void booksFind(String&,const String&) const;
	void booksSortAscending(const String&);
	void booksSortDescending(const String&);
	void booksAdd();
	void booksRemove(const String&);
	void usersAdd(const String&, const String&);
	void usersRemove(String&);
	User& activeUser();
private:
	UserStore users;
	BookStore books;
};

