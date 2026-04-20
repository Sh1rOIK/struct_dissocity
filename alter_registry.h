#pragma once
#include "alter.h"
#include <string>
#include <vector>

class Alter_registry {
private:
	static std::vector<Alter> all_alters;
public:

	static const std::vector<Alter>& getAlters();
	static void addAlter(const std::string& name, const std::string& func);
	static void showAlter();
};