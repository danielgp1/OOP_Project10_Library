#pragma once
#include "String.h"
#include "Vector.h"
class Book
{
public:
	Book();
	void setTitle(const String&);
	void setAuthor(const String&);
	void setGenre(const String&);
	void setSummary(const String&);
	void setYear(const size_t);
	void setTags(const Vector<String>&);
	void setRating(const double);
	void setId(const size_t);
	void printBriefly() const;
	void printDetailed() const;
	void loadBook(std::istream&);
	void saveBook(std::ostream&) const;
	size_t getID() const;
	const String& getTitle() const; 
	const String& getAuthor() const; 
	const Vector<String>& getTags() const;
	const size_t& getYear() const;
	const double& getRating() const;
private:
	String title;
	String author;
	String genre;
	String summary;
	Vector<String> tags;
	size_t year;
	double rating;
	size_t id;
};
