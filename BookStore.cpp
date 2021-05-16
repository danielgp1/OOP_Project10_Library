#include "BookStore.h"
#include "Book.h"
#include <iostream>

BookStore::BookStore()
{
	this->id = 1;
	this->total = 0;
}

void BookStore::print() const
{
	size_t size = books.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << books[i].getAuthor() << " | ";
	}
}

void BookStore::allBooksBrieflyInfo() const
{
	size_t size = books.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		books[i].printBriefly();
		if(i != size - 1)
			std::cout << std::endl;
	}
}

void BookStore::bookDetailedInfo(const size_t id) const
{
	size_t size = books.getSize();
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

void BookStore::findBook(const String& option, const String& description) const
{
	size_t size = books.getSize();
	bool atLeastOne = false;
	if (option == "title")
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (books[i].getTitle() == description)
			{
				atLeastOne = true;
				std::cout << "Book ID: " << books[i].getID() << std::endl;
			}
		}
		if (atLeastOne == false)
		{
			std::cout << "Book not found!\n";
			return;
		}
	}
	else if (option == "author")
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (books[i].getAuthor() == description)
			{
				atLeastOne = true;
				std::cout << "Book ID: " << books[i].getID() << std::endl;
			}
		}
		if (atLeastOne == false)
		{
			std::cout << "Book not found!\n";
			return;
		}
	}
	else if (option == "tag")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < books[i].getTags().getSize(); ++j)
			{
				if (books[i].getTags()[j] == description)
				{
					atLeastOne = true;
					std::cout << "Book ID: " << books[i].getID() << std::endl;
					break;
				}
			}
		}
		if (atLeastOne == false)
		{
			std::cout << "Book not found!\n";
			return;
		}
	}
	else
	{
		std::cout << "Invalid option!\n";
	}
}

void BookStore::sortBooksAscending(const String& option)
{
	size_t size = books.getSize();
	if (size == 0)
	{
		std::cout << "There are no books!\n";
		return;
	}
	if (size == 1)
	{
		std::cout << "There is only one book!\n";
		return;
	}
	if (option == "title")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if ( !(books[i].getTitle() < books[j].getTitle()))
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else if (option == "author")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (!(books[i].getAuthor() < books[j].getAuthor()))
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else if (option == "year")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if ( !(books[i].getYear() < books[j].getYear()))
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else if (option == "rating")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (!(books[i].getRating() < books[j].getRating()))
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else
	{
		std::cout << "Invalid option!\n";
		return;
	}
	std::cout << "Books sorted by " << option << " successfully!\n";
}

void BookStore::sortBooksDescending(const String& option)
{
	size_t size = books.getSize();
	if (size == 0)
	{
		std::cout << "There are no books!\n";
		return;
	}
	if (size == 1)
	{
		std::cout << "There is only one book!\n";
		return;
	}
	if (option == "title")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (books[i].getTitle() < books[j].getTitle())
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else if (option == "author")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (books[i].getAuthor() < books[j].getAuthor())
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else if (option == "year")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (books[i].getYear() < books[j].getYear())
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else if (option == "rating")
	{
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (books[i].getRating() < books[j].getRating())
				{
					Book temp;
					temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}
	else
	{
		std::cout << "Invalid option!\n";
		return;
	}
	std::cout << "Books sorted by " << option << " successfully!\n";	
}

void BookStore::addBook()
{
	String title;
	std::cout << "Title: ";
	std::cin >> title;
	size_t size = books.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		if (books[i].getTitle() == title)
		{
			std::cout << "This book already exists!\n";
			return;
		}
	}
	String author;
	std::cout << "Author: ";
	std::cin >> author;

	String genre;
	std::cout << "Genre: ";
	std::cin >> genre;

	String summary;
	std::cout << "Summary: ";
	std::cin >> summary;

	String helper;
	size_t helperSize;
	std::cout << "Tags: ";
	std::cin >> helper;
	helperSize = helper.getSize();

	Vector<String> tags;
	String ourTag = "";
	for (size_t i = 0; i < helperSize; ++i)
	{
		if (helper[i] == ' ')
		{
			tags.pushBack(ourTag);
			ourTag = "";
			continue;
		}
		ourTag += helper[i];
	}
	if (ourTag != "")
		tags.pushBack(ourTag);

	size_t year;
	std::cout << "Year: ";
	while (!(std::cin >> year))
	{
		std::cin.clear(); // clear input buffer to restore cin to a usable state
		std::cin.ignore(INT_MAX, '\n'); // discard the row
		std::cout << "You can only enter numbers for an year!\n";
		std::cout << "Year: ";
	} 
	

	double rating;
	std::cout << "Rating: ";
	while (!(std::cin >> rating))
	{
		std::cin.clear(); // clear input buffer to restore cin to a usable state
		std::cin.ignore(INT_MAX, '\n'); // discard the row
		std::cout << "You can only enter numbers for a rating!\n";
		std::cout << "Rating: ";
	}

	Book newBook;
	newBook.setTitle(title);
	newBook.setAuthor(author);
	newBook.setGenre(genre);
	newBook.setSummary(summary);
	newBook.setYear(year);
	newBook.setTags(tags);
	newBook.setRating(rating);
	newBook.setId(id++);
	books.pushBack(newBook);
	this->total++;
	std::cout << "New book successfully added!\n";
	std::cin.ignore();
}

void BookStore::removeBook(const String& title)
{
	size_t size = books.getSize();
	int indexOfBook = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (books[i].getTitle() == title)
		{
			indexOfBook = i;
			break;
		}
	}
	if (indexOfBook == -1)
	{
		std::cout << "Book not found!\n";
		return;
	}
	books.removeAt(indexOfBook);
	this->total--;
	std::cout << "Book successfully removed!\n";
}


size_t BookStore::getSize() const
{
	return this->books.getSize();
}


void BookStore::loadBooks(std::ifstream& in,size_t skip)
{
	for (int i = 0; i < skip; ++i) 
	{
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	in >> this->total;
	for (size_t i = 0; i < total; ++i)
	{
		Book book;
		book.loadBook(in);
		books.pushBack(book);
	}
	this->id = books[books.getSize() - 1].getID() + 1;
}

void BookStore::saveBooks(std::ofstream& out)
{
	size_t size = books.getSize();
	out << this->total << "\n";
	for (size_t i = 0; i < size; ++i)
	{
		books[i].saveBook(out);
	}
}

void BookStore::clear()
{
	BookStore clean;
	*this = clean;
}