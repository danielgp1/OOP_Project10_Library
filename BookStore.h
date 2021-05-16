#pragma once
#include "Book.h"
#include "String.h"
class BookStore
{
public:
	BookStore();
	void print() const;
	void allBooksBrieflyInfo() const;
	void bookDetailedInfo(const size_t) const;
	void findBook(const String&,const String&) const;
	void sortBooksAscending(const String&);
	void sortBooksDescending(const String&);
	void addBook();
	void removeBook(const String&);
	void loadBooks(std::ifstream&,size_t);
	void saveBooks(std::ofstream&);
	size_t getSize() const;
	void clear();
private:
	Vector<Book> books;
	size_t total;
	size_t id;
};