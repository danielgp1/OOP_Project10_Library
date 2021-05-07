#include "CommandMenu.h"
#include  "Library.h"
#include <iostream>
#include <cstring>

CommandMenu::CommandMenu()
{
	allCommands.pushBack("open"); // 0
	allCommands.pushBack("close"); // 1
	allCommands.pushBack("save"); // 2
	allCommands.pushBack("save as"); // 3
	allCommands.pushBack("help"); // 4
	allCommands.pushBack("login"); // 5
	allCommands.pushBack("logout"); // 6
	allCommands.pushBack("books all"); // 7
	allCommands.pushBack("books info"); // 8
	allCommands.pushBack("books find"); // 9
	allCommands.pushBack("books sort"); // 10
	allCommands.pushBack("books add"); // 11
	allCommands.pushBack("books remove");// 12
	allCommands.pushBack("users add"); // 13
	allCommands.pushBack("users remove"); // 14
	allCommands.pushBack("exit"); // 15
}

void CommandMenu::startLibrary()
{
	Library library;
	int commandIndex = -1;
	do
	{
		commandIndex = -1;
		command = "";
		std::cout << "Enter a command. Enter \"help\" to see the available commands.\n";
		std::cin >> command;
		this->getCommand();
		this->checkSecondCommand(theCommand[2]);
		this->getParameters();
		for (size_t i = 0; i < allCommands.getSize(); ++i)
		{
			if (theCommand[0] == allCommands[i])
			{
				commandIndex = i;
				break;
			}
			
		}
		std::cout << "------------------------------------------------------------------------------------\n";
		switch (commandIndex)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.help();
			break;	
		}
		case 5:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.logIn();
			break;
		}
		case 6:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.logOut();
			break;
		}
		case 7:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.booksAll();
			break;
		}
		case 8:
		{
			if (parameters.getSize() >= 2 || parameters.getSize() <= 0)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.booksInfo(parameters[0].StringToNumber());
			break;
		}
		case 9:
		{
			if (parameters.getSize() >= 3 || parameters.getSize() <= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.booksFind(parameters[0], parameters[1]);
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.booksAdd();
			break;
		}
		case 12:
		{
			if (parameters.getSize() >= 2 || parameters.getSize() <= 0)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.booksRemove(parameters[0]);
			break;
		}
		case 13:
		{
			if (parameters.getSize() >= 3 || parameters.getSize() <= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.usersAdd(parameters[0], parameters[1]);
			break;
		}
		case 14:
		{
			if (parameters.getSize() >= 2 || parameters.getSize() <= 0)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.usersRemove(parameters[0]);
			break;
		}
		case 15:
		{
			std::cout << "Good Bye!\n";
			break;
		}
		default:
		{
			std::cout << "Invalid command!\n";
			break;
		}
		}
		std::cout << "------------------------------------------------------------------------------------\n";
	} while (theCommand[0] != "exit");
}

void CommandMenu::getCommand()
{
	size_t size = command.getSize();
	theCommand.clear();
	String ourCommand = "";
	String helperCommand = "";
	int helperIndex = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (command[i] == ' ')
		{
			helperIndex = i + 1;
			theCommand.pushBack(ourCommand);	
			break;
		}
		ourCommand += command[i];
	}
	theCommand.pushBack(ourCommand);
	for (size_t j = helperIndex; j < size; ++j)
	{
		if (command[j] == ' ')
		{
			theCommand.pushBack(helperCommand);
			break;
		}
		helperCommand += command[j];
	}
	if (theCommand[2] != helperCommand)
		theCommand.pushBack(helperCommand);
	checkCommand(ourCommand, helperCommand, theCommand);
}

void CommandMenu::checkCommand(String& command1,String& command2,Vector<String>& vector1)
{
	if (command1 == "save")
	{
		if (command2 == "as")
			vector1[0] = "save as";
	}
	else if (command1 == "users")
	{
		if (command2 == "add")
			vector1[0] = "users add";
		else if (command2 == "remove")
			vector1[0] = "users remove";
	}
	else if (command1 == "books")
	{
		if (command2 == "all")
			vector1[0] = "books all";
		else if (command2 == "info")
			vector1[0] = "books info";
		else if (command2 == "find")
			vector1[0] = "books find";
		else if (command2 == "sort")
			vector1[0] = "books sort";
		else if (command2 == "add")
			vector1[0] = "books add";
		else if (command2 == "remove")
			vector1[0] = "books remove";
	}
}


void CommandMenu::getParameters()
{
	size_t size;
	size = command.getSize();
	parameters.clear();
	String space = " ";
	String parameter = "";
	for (size_t i = 0; i < size; ++i)
	{
		if (command[i] == ' ' && command[i - 1] == ' ')
		{
			continue;
		}
		if (command[i] == ' ')
		{
			if (parameter == theCommand[0] || parameter == theCommand[1] || parameter == theCommand[2])
			{
				parameter = "";
				continue;
			}
			parameters.pushBack(parameter);
			parameter = "";
			continue;
		}
		parameter += command[i];
	}
	if(parameter != "" && parameter != theCommand[0] && parameter != theCommand[1] && parameter != theCommand[2])
		parameters.pushBack(parameter);
}

void CommandMenu::checkSecondCommand(String& command)
{
	if (command != "info" && command != "find" && command != "sort" && command != "add" && command != "remove" && command != "all" && command != "as")
		this->theCommand.popBack();
}

