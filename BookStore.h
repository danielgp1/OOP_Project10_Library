#pragma once
#include "Book.h"
#include "String.h"
class BookStore
{
public:
	enum class option { TITLE, AUTHOR, YEAR, RATING };
	BookStore();

	const size_t getSize() const;

	void swap(Book&, Book&);
	void allBooksBrieflyInfo() const;
	void bookDetailedInfo(const size_t) const;
	void findBook(const String&,const String&) const;
	void sortBooksAscending(const String&);
	void sortBooksDescending(const String&);

	void addBook();
	void removeBook(const String&);
	void clear();

	void loadBooks(std::ifstream&,size_t);
	void saveBooks(std::ofstream&);

	Book& operator[](const size_t) const; // just for testing
private:
	Vector<Book> books;
	size_t total;
	size_t id;
};