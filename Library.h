#pragma once
#include "UserStore.h"
#include "BookStore.h"
class Library
{
public:
	Library();
	void open();
	void save();
	void saveAs(const char*);
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
	bool correctUsersDatabase(const String&);
	User& activeUser();
private:
	UserStore users;
	BookStore books;
	bool usersIsOpened;
	bool booksIsOpened;
	bool isSaved;
	bool isChanged;
	String usersFileName;
	String booksFileName;
};

