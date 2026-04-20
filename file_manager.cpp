#include "file_manager.h"
#include "alter_registry.h"
#include "alter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <string_view>

void File_manager::saveToFile(const std::string& filename, const Alter_registry& registry) {
	std::ofstream file(filename);
	if (!file) return;
		
	for (auto& alter : registry.getAlters()) {
		file << alter.getName() << "|" << alter.getFunc() << "\n";
	}
	
	std::cout << "Saved to " << filename << std::endl;
}

void File_manager::loadFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file) return;

	std::string line;
	while (std::getline(file, line)) {
		if (line.find('|') == std::string::npos) {
			std::cout << "[Error] file is broken!\n";

			file.close();
			char choice;
			std::cout << "Delete broken file?(y/n): ";

			while (true) {
				if (!(std::cin >> choice)) {
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					continue;
				}
				std::cin.ignore(10000, '\n');
				if (choice == 'y' || choice == 'Y') {
					File_manager::removeFile(filename);
					std::cout << "File is delete!\n"; break;
				}
				else {
					std::cout << "[Error] input char is not correct\n";
				}
			}
			break;
		}
		std::string_view sv = line;
		size_t delimiter = line.find('|');

		if (delimiter != std::string::npos) {
			std::string name(sv.substr(0, delimiter));
			std::string func(sv.substr(delimiter + 1));
			Alter_registry::addAlter(name, func);
		}
	}
}

void File_manager::removeFile(const std::string& filename) {
	std::filesystem::path p(filename);

	if (std::filesystem::exists(p)) {
		std::filesystem::remove(p);
		std::cout << "[System] file " << filename << "delete successfully\n";
	}
	else {
		std::cout << "[Error] can't delete: file " << filename << "not find\n";
	}
}