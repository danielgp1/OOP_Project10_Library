#include "Book.h"

Book::Book()
{
	this->title = "";
	this->author = "";
	this->genre = "";
	this->summary = "";
	this->year = 0;
	this->rating = 0;
	this->id = 0;
}

void Book::setTitle(const String& _title)
{
	this->title = _title;
}

void Book::setAuthor(const String& _author)
{
	this->author = _author;
}

void Book::setGenre(const String& _genre)
{
	this->genre = _genre;
}

void Book::setSummary(const String& _summary)
{
	this->summary = _summary;
}

void Book::setYear(const size_t _year)
{
	this->year = _year;
}

void Book::setTags(const Vector<String>& _tags)
{
	this->tags = _tags;
}

void Book::setRating(const double _rating)
{
	this->rating = _rating;
}

void Book::setId(const size_t _id)
{
	this->id = _id;
}

void Book::printBriefly() const
{
	std::cout << "Title:  " << this->title << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Genre:  " << this->genre << std::endl;
	std::cout << "ID:     " << this->id << std::endl;
}

void Book::printDetailed() const
{
	std::cout << "Title:   " << this->title << std::endl;
	std::cout << "Author:  " << this->author << std::endl;
	std::cout << "Genre:   " << this->genre << std::endl;
	std::cout << "Summary: " << this->summary << std::endl;
	std::cout << "Tags:    "; this->tags.print(); std::cout << std::endl;
	std::cout << "Year:    " << this->year << std::endl;
	std::cout << "Rating:  " << this->rating << std::endl;
	std::cout << "ID:      " << this->id << std::endl;
}

void Book::loadBook(std::istream& in)
{
	in >> title;
	if (title == "\n")
		in >> title;
	in >> author;
	in >> genre;
	in >> summary;
	in >> tags;
	in >> year;
	in >> rating;
	in >> id;
}

void Book::saveBook(std::ostream& out) const
{
	out << title << "\n";
	out << author << "\n";
	out << genre << "\n";
	out << summary << "\n";
	out << tags << "\n";
	out << year << "\n";
	out << rating << "\n";
	out << id << "\n";
}

size_t Book::getID() const
{
	return this->id;
}

const String& Book::getTitle() const
{
	return this->title;
}

const String& Book::getAuthor() const
{
	return this->author;
}

const Vector<String>& Book::getTags() const
{
	return this->tags;
}

const size_t& Book::getYear() const
{
	return this->year;
}

const double& Book::getRating() const
{
	return this->rating;
}