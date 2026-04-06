#pragma once 
#include <string>

class Alter {
private:
	int callCounter = 0;
	std::string name_alter;
	std::string function_alter;
public:
	void addAlter(const std::string& name, const std::string& func);
	void setAlters(std::string n, std::string f);
	void alter_info();
	struct_dissociaty(std::string name, std::string func);
};