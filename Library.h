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
	void booksInfo(const size_t) const;
	void booksFind(const String&,const String&) const;
	void booksSort(const String&);
	void booksAdd(const Book&);
	void booksRemove(const size_t);
	void usersAdd(const String&, const String&);
	void usersRemove(const String&);

private:
	UserStore users;
	BookStore books;
};

