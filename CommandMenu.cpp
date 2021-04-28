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
	User admin;
	int commandIndex = -1;
	do
	{
		commandIndex = -1;
		command = "";
		std::cout << "Enter a command. Enter \"help\" to see the available commands.\n";
		std::cin >> command;
		this->getCommand();
		for (size_t i = 0; i < allCommands.getSize(); ++i)
		{
			if (theCommand[0] == allCommands[i])
			{
				//std::cout << theCommand[0] << " " << i << std::endl;
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
			library.help();
			break;
		}
		case 5:
		{
			library.logIn();
			break;
		}
		case 6:
		{
			library.logOut();
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
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
	theCommand.clear();
	String ourCommand = "";
	String helperCommand = "";
	int helperIndex = 0;
	for (size_t i = 0; i < command.getSize(); ++i)
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
	for (size_t j = helperIndex; j < command.getSize(); ++j)
	{
		if (command[j] == ' ')
		{
			break;
		}
		helperCommand += command[j];
	}
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
