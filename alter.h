#pragma once 
#include <string>

class Alter {
private:
	int callCounter = 0;
	std::string name_alter;
	std::string function_alter;
public:
	Alter();
	Alter(std::string name, std::string func);
	std::string getName() const;
	std::string getFunc() const;
	void setAlters(std::string n, std::string f);
	void alter_info();
};