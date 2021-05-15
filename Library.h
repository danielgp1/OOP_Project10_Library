#pragma once
#include "UserStore.h"
#include "BookStore.h"
class Library
{
public:
	Library();
	void open(const String&);
	void save();
	void saveAs(const String&);
	void close();
	void logIn();
	void logOut();
	void exit();
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
	bool isOpened;
	bool isSaved;
	bool isChanged;
	String FileName;
};

