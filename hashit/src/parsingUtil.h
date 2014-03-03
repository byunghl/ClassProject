#ifndef PARSINGUTIL_H
#define PARSINGUTIL_H
#include <string>
#include <iostream>

// general parser
std::string getFirstWord(std::string rawInputStr);
bool hasEmptyCharOffset(std::string rawInputStr);
int positionOfFirstEmptyChar(std::string rawInputStr);
int countEmptyChars(std::string rawInputStr);

// specialized parser
bool isDebugCommand(std::string command);
bool checkValidNumberOfArguments(std::string rawStr, std::string firstWord);
std::string* twoParamParser(std::string parameters);
std::string oneParamParser(std::string str);
bool checkValidBasicCommand(std::string firstWord);

#endif 
