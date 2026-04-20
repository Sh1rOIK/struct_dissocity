#include "alter_registry.h"
#include <string>
#include <utility>
#include <iostream>

void Alter_registry::addAlter(const std::string& name, const std::string& func) {
	all_alters.emplace_back(name, func);
}

void Alter_registry::showAlter() {
	for (auto& list : all_alters)
		list.alter_info();
}

const std::vector<Alter>& Alter_registry::getAlters() {
	return all_alters;
}