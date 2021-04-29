#include "Library.h"

Library::Library()
{
	users.addUser("admin", "i<3c++");
	users[0].setAdmin(true);
	users[0].setLoggedIn(true);
}

void Library::logIn()
{
	if (users.activeUserIndex() != -1)
	{
		std::cout << "Another user is already logged in! Please log out!\n";
		return;
	}
	size_t counter = 0;
	int index = -1;
	String name;
	String password;
	do
	{
		std::cout << "Enter your username: ";
		std::cin >> name;
		for (size_t i = 0; i < users.getSize(); ++i)
		{
			if (name == users[i].getName())
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			counter++;
			std::cout << "User with that username not found! Remaining tries: " << 5 - counter << std::endl;
			name = "";
		}
	} while (index == -1 && counter <5);
	if (counter >= 5)
	{
		std::cout << "Try again later!\n";
		return;
	}
	counter = 0;
	do
	{
		std::cout << "Enter your password: ";
		std::cin >> password;
		if (users[index].getPassword() == password)
		{
			users[index].setLoggedIn(true);
			std::cout << "Welcome " << name << "!\n";
			return;
		}
		counter++;
		std::cout << "Incorrect password! Remaining tries: " << 5 - counter << std::endl;
		password = "";
	} while (counter < 5);
	std::cout << "Try again later!\n";
	return;
}

void Library::logOut()
{
	if (users.activeUserIndex() == -1)
	{
		std::cout << "No one is logged in!\n";
		return;
	}
	users[users.activeUserIndex()].setLoggedIn(false);
	std::cout << "You have successfully logged out!\n";
	return;
}

void Library::help() const
{
	std::cout << "Available commands:\n";
	std::cout << "help                                       opens the help menu\n";
	std::cout << "open <file name>                           opens <file name>\n";
	std::cout << "close                                      closes the current file\n";
	std::cout << "save                                       saves the current file\n";
	std::cout << "save as <location>                         saves the current file in <location>\n";
	std::cout << "exit                                       exits the program\n";
	std::cout << "login                                      logs in in the system\n";
	std::cout << "logout(*)                                  logs out of the system\n";
	std::cout << "books all(*)                               print the info of all books\n";
	std::cout << "books find <what> <description>(*)         finds if the book exists\n";
	std::cout << "books info <id>(*)                         prints the info of a book\n";
	std::cout << "books sort <by what (asc|desc)>(*)         sorts the books\n";
	std::cout << "books add(*)(^)                            adds a new book\n";
	std::cout << "books remove(*)(^)                         removes a book\n";
	std::cout << "users add <username> <password>(*)(^)      adds a new user\n";
	std::cout << "users remove <username>(*)(^)              removes a user\n\n";
	std::cout << "(*) - requires to be logged in | (^) - requires admin rights\n";
}

void Library::booksAll() const
{
	if (users.activeUserIndex() == -1)
	{
		std::cout << "You have to be logged in!\n";
		return;
	}
	if (books.getSize() == 0)
	{
		std::cout << "No available books!\n";
		return;
	}
	books.allBooksBrieflyInfo();
}

void Library::usersAdd(const String& name, const String& password)
{
	if (users.activeUserIndex() == -1)
	{
		std::cout << "You have to be logged in!\n";
		return;
	}
	User active;
	active = activeUser();
	if (active.getAdmin() == false)
	{
		std::cout << "Admin rights required!\n";
		return;
	}
	users.addUser(name, password);
	std::cout << "New user successfully added!\n";
}

void Library::usersRemove(String& name)
{
	if (users.activeUserIndex() == -1)
	{
		std::cout << "You have to be logged in!\n";
		return;
	}
	User active;
	active = activeUser();
	if (active.getAdmin() == false)
	{
		std::cout << "Admin rights required!\n";
		return;
	}
	if (name == active.getName())
	{
		std::cout << "You can't remove yourself!\n";
		return;
	}
	users.removeUser(name);
	std::cout << "User successfully removed!\n";
}

User& Library::activeUser()
{
	return users[users.activeUserIndex()];
}
