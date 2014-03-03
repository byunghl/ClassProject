#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <string>
#include "HashMap.hpp"
#include "parsingUtil.h"


class Manager{

public:

	Manager();
	void runCommand();
	void commandChecker(std::string rawStr, bool &isDebugMode);
	void debugModeSwitch(std::string command, bool &isDebugMode);
	void debugCommandExecuter(std::string command);
	void basicCommandExecutor(std::string str, bool isDebugMode);

private:


	HashMap myHashMap;
	bool isDebugMode;
    	std::string command;


};



#endif