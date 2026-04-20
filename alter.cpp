#include "alter.h"
#include <string>
#include <utility>
#include <iostream>

Alter::Alter() : name_alter("none"), function_alter("none"), callCounter(0) {}

Alter::Alter(std::string name, std::string func) : 
	name_alter(std::move(name)), function_alter(std::move(func)) {}

std::string Alter::getName() const {
	return name_alter;
}

std::string Alter::getFunc() const {
	return function_alter;
}

void Alter::setAlters(std::string n, std::string f) {
	name_alter = std::move(n);
	function_alter = std::move(f);
}

void Alter::alter_info() {
	callCounter++;
	std::cout << "Call: " << callCounter << "| Name: "
		<< name_alter << "| Function: " << function_alter << "\n";
}