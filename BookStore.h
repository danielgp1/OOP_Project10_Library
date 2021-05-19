#pragma once
#include "Book.h"
#include "String.h"
class BookStore
{
public:
	enum class option { TITLE, AUTHOR, YEAR, RATING };
	BookStore();
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
	void swap(Book&, Book&);
private:
	Vector<Book> books;
	size_t total;
	size_t id;
};