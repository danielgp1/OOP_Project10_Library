#include "CommandMenu.h"
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
			if (parameters.getSize() >= 2 || parameters.getSize() <= 0)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.open(parameters[0]);
			break;
		}
		case 1:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.close();
			break;
		}
		case 2:
		{
			if (parameters.getSize() >= 1)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.save();
			break;
		}
		case 3:
		{
			if (parameters.getSize() >= 2 || parameters.getSize() <= 0)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			library.saveAs(parameters[0]);
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
			if (parameters.getSize() >= 3 || parameters.getSize() <= 0)
			{
				std::cout << "Invalid parameters count!\n";
				break;
			}
			if (parameters[1] == "" || parameters[1] == "asc")
			{
				library.booksSortAscending(parameters[0]);
			}
			else if (parameters[1] == "desc")
			{
				library.booksSortDescending(parameters[0]);
			}
			else
				std::cout << "Invalid second parameter!\n";
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
			library.exit();
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
		if ((command[i] == ' ' && ourCommand == "") || (command[i] == 9 && ourCommand == ""))
		{
			continue;
		}
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
		if ((command[j] == ' ' && helperCommand == "") || (command[j] == 9 && helperCommand == ""))
		{
			continue;
		}
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

void CommandMenu::checkCommand(const String& command1,const String& command2,const Vector<String>& vector1)
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
	String parameter = "";
	for (size_t i = 0; i < size; ++i)
	{
		if ((command[i] == ' ' && parameter == "") || (command[i] == 9 && parameter == ""))
		{
			continue;
		}
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

void CommandMenu::setCommand(const String& _command)
{
	this->command = _command;
}

Vector<String>& CommandMenu::getTheCommand() 
{
	return this->theCommand;
}

Vector<String>& CommandMenu::getTheParameters()
{
	return this->parameters;
}

void CommandMenu::checkSecondCommand(const String& command)
{
	if (command != "info" && command != "find" && command != "sort" && command != "add" && command != "remove" && command != "all" && command != "as")
		this->theCommand.popBack();
}