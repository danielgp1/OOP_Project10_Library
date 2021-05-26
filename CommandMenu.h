#pragma once
#include "Vector.h"
#include "String.h"
#include "Library.h"

class CommandMenu
{
public:
	CommandMenu();
	void startLibrary();
	void getCommand();
	void checkSecondCommand(const String&);
	void checkCommand(const String&,const String&,const Vector<String>&);
	void getParameters();

	void setCommand(const String&); // just for testing
	Vector<String>& getTheCommand(); // just for testing
	Vector<String>& getTheParameters(); // just for testing
private:
	Vector<String> allCommands;
	Vector<String> theCommand;
	Vector<String> parameters;
	String command;
};