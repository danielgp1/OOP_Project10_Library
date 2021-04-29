#pragma once
#include "Book.h"
#include "String.h"
class BookStore
{
public:
	BookStore();
	~BookStore();
	BookStore(const BookStore&);
	BookStore& operator=(const BookStore&);
	//Book& operator[](int);
	void allBooksBrieflyInfo() const;
	void bookDetailedInfo(const size_t) const;
	void findBook(const String&,const String&) const;
	void sortBooks(const String&);
	void addBook(const Book&);
	void removeBook(const String&);
	size_t getSize() const;
private:
	Book* books;
	size_t size;
	size_t capacity;
	void copy(const BookStore&);
	void erase();
	void resize();
};

