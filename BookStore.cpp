#include "BookStore.h"
#include "Book.h"
#include <iostream>

BookStore::BookStore()
{
	this->id = 1;
	this->total = 0;
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

void BookStore::sortBooksAscending(const String& input)
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
	option ourOption;
	if (input == "title")
		ourOption = option::TITLE;
	else if (input == "author")
		ourOption = option::AUTHOR;
	else if (input == "year")
		ourOption = option::YEAR;
	else if (input == "rating")
		ourOption = option::RATING;
	else
	{
		std::cout << "Invalid option!\n";
		return;
	}
	auto myLambda = [ourOption](const Book& b1, const Book& b2) -> bool
	{
		switch (ourOption)
		{
		case option::TITLE:
			return b1.getTitle() < b2.getTitle();
			break;
		case option::AUTHOR:
			return b1.getAuthor() < b2.getAuthor();
			break;
		case option::YEAR:
			return b1.getYear() < b2.getYear();
			break;
		case option::RATING:
			return b1.getRating() < b1.getRating();
			break;
		default:
			break;
		}
	};
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			if (!myLambda(books[i], books[j]))
				swap(books[i], books[j]);
		}
	}
	std::cout << "Books sorted by " << input << " successfully!\n";
}

void BookStore::sortBooksDescending(const String& input)
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
	option ourOption;
	if (input == "title")
		ourOption = option::TITLE;
	else if (input == "author")
		ourOption = option::AUTHOR;
	else if (input == "year")
		ourOption = option::YEAR;
	else if (input == "rating")
		ourOption = option::RATING;
	else
	{
		std::cout << "Invalid option!\n";
		return;
	}
	auto myLambda = [ourOption](const Book& b1, const Book& b2) -> bool
	{
		switch (ourOption)
		{
		case option::TITLE:
			return b1.getTitle() < b2.getTitle();
			break;
		case option::AUTHOR:
			return b1.getAuthor() < b2.getAuthor();
			break;
		case option::YEAR:
			return b1.getYear() < b2.getYear();
			break;
		case option::RATING:
			return b1.getRating() < b1.getRating();
			break;
		default:
			break;
		}
	};
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			if (myLambda(books[i], books[j]))
				swap(books[i], books[j]);
		}
	}
	std::cout << "Books sorted by " << input << " successfully!\n";
}

void BookStore::addBook()
{
	size_t size = 0;
	std::cout << "Please use \"_\" instead of blank space!\n";
	String title = "";
	do
	{
		std::cout << "Title: ";
		std::cin >> title;
		size = title.getSize();
		for (size_t i = 0; i < size; ++i)
		{
			if (title[i] == ' ')
			{
				std::cout << "Please use \"_\" instead of blank space!\n";
				title = "";
				break;
			}
		}
	} while (title == "");
	size = books.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		if (books[i].getTitle() == title)
		{
			std::cout << "This book already exists!\n";
			return;
		}
	}
	String author = "";
	do
	{
		std::cout << "Author: ";
		std::cin >> author;
		size = author.getSize();
		for (size_t i = 0; i < size; ++i)
		{
			if (author[i] == ' ')
			{
				std::cout << "Please use \"_\" instead of blank space!\n";
				author = "";
				break;
			}
		}
	} while (author == "");
	
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


const size_t BookStore::getSize() const
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

Book& BookStore::operator[](const size_t index) const
{
	return this->books[index];
}

void BookStore::clear()
{
	BookStore clean;
	*this = clean;
}

void BookStore::swap(Book& a, Book& b)
{
	Book temp;
	temp = a;
	a = b;
	b = temp;
}
