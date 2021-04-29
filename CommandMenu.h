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
	void checkCommand(String&, String&, Vector<String>&);
	void getParameters();
	void checkSecondCommand(String&);
private:
	Vector<String> allCommands;
	Vector<String> theCommand;
	Vector<String> parameters;
	String command;
};

