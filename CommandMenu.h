#pragma once
#include "Vector.h"
#include "String.h"
#include "UserStore.h"
#include "BookStore.h"

class CommandMenu
{
public:
	CommandMenu();
	void startLibrary();
	void getCommand();
	void checkCommand(String& command1,String& command2, Vector<String>& vector1);
private:
	Vector<String> allCommands;
	Vector<String> theCommand;
	String command;
};

