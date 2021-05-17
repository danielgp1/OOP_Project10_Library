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
	void checkSecondCommand(const String&);
	void checkCommand(const String&,const String&,const Vector<String>&);
	void getParameters();
private:
	Vector<String> allCommands;
	Vector<String> theCommand;
	Vector<String> parameters;
	String command;
};