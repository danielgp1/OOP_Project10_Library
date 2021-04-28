#include "BookStore.h"
#include "Book.h"
#include <iostream>
BookStore::BookStore()
{
	this->size = 0;
	this->capacity = 8;
	this->books = new Book[capacity];
}

BookStore::~BookStore()
{
	this->erase();
}

BookStore::BookStore(const BookStore& other)
{
	this->copy(other);
}

BookStore& BookStore::operator=(const BookStore& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

void BookStore::allBooksBrieflyInfo() const
{
	for (size_t i = 0; i < size; ++i)
	{
		books[i].printBriefly();
		std::cout << std::endl;
	}
}

void BookStore::bookDetailedInfo(const size_t id) const
{
	int indexBook = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (books[i].getID() == id)
		{
			indexBook = i;
			break;
		}
	}
	if (indexBook == -1)
	{
		std::cout << "Book not found!\n";
		return;
	}
	books[indexBook].printDetailed();
}

void BookStore::copy(const BookStore& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	for (size_t i = 0; i < size; ++i)
	{
		this->books[i] = other.books[i];
	}
}

void BookStore::erase()
{
	delete[] this->books;
}

void BookStore::resize()
{
	this->capacity *= 2;
	Book* temp = new Book[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		temp[i] = this->books[i];
	}
	delete[] this->books;
	this->books = temp;
}
