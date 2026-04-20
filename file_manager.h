#pragma once
#include <fstream>

class File_manager {
public:
	static void saveToFile(const std::string& filename, const Alter_registry& registry);
	static void loadFromFile(const std::string& filename);
	static void removeFile(const std::string& filename);
};