#pragma once
#include "String.h"
#include "Vector.h"
class Book
{
public:
	Book();
	void printBriefly() const;
	void printDetailed() const;
	void loadBook(std::istream&);
	void saveBook(std::ostream&) const;
	Book& operator=(const Book&);
	size_t getID() const;
	String getTitle() const;
	String getAuthor() const;
	Vector<String> getTags() const;
private:
	String title;
	String author;
	String genre;
	String summary;
	size_t year;
	Vector<String> tags;
	double rating;
	size_t id;
};
