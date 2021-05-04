#include "Book.h"

Book::Book()
{
	this->title = "Default";
	this->author = "Default";
	this->genre = "Default";
	this->summary = "Default";
	this->year = 0;
	this->tags.pushBack("Default");
	this->rating = 0;
	this->id = 0;
}

void Book::printBriefly() const
{
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Genre: " << this->genre << std::endl;
	std::cout << "ID: " << this->id << std::endl;
}

void Book::printDetailed() const
{
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Genre: " << this->genre << std::endl;
	std::cout << "Summary: " << this->summary << std::endl;
	std::cout << "Year: " << this->year << std::endl;
	std::cout << "Tags: " << this->tags << std::endl;
	std::cout << "Rating: " << this->rating << std::endl;
	std::cout << "ID: " << this->id << std::endl;
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		this->title = other.title;
		this->author = other.author;
		this->genre = other.genre;
		this->summary = other.summary;
		this->year = other.year;
		this->tags = other.tags;
		this->rating = other.rating;
		this->id = other.id;
	}
	return *this;
}

size_t Book::getID() const
{
	return this->id;
}

String Book::getTitle() const
{
	return this->title;
}

String Book::getAuthor() const
{
	return this->author;
}

Vector<String> Book::getTags() const
{
	return this->tags;
}
