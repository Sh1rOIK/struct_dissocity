#include <vector>
#include "alter.h"
#include "alter_registry.h"
#include "file_manager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <string_view>

int main() {
	Alter_registry registry;
	
	File_manager::loadFromFile("alters.txt");
	std::string name;
	std::string func;

	int count;

	while (true) {

		std::cout << "Count: ";
		std::cin >> count;
		std::cin.ignore();
		if (count > 0) {
			break;
		}
		else {
			std::cout << "[Error] count need be positive. " << std::endl;
		}

	}

	for (int i = 0; i < count; i++) {
		std::cout << "\nAlter # " << i + 1 << ":\n";

		std::cout << "Name: ";
		std::getline(std::cin, name);
		std::cout << "Func: ";
		std::getline(std::cin, func);

		Alter_registry::addAlter(name, func);
	}

	std::cout << "\n--- All alters ---\n";
	Alter_registry::showAlter();

	char ch;
	std::cout << "\nsave&(y/n): ";
	std::cin >> ch;

	while (true) {

		if (ch == 'y' || ch == 'Y') {
			File_manager::saveToFile("alters.txt", registry); break;
		}
		else if (ch == 'n' || ch == 'N') {
			std::cout << "File is not saved" << std::endl; break;
		}
		else {
			std::cout << "[Error] input char is not correct" << std::endl;
		}
	}

	return 0;
}