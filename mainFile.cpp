#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <string_view>

class struct_dissociaty {

private:
	int callCounter = 0;
	std::string name_alter;
	std::string function_alter;
	static std::vector<struct_dissociaty> all_alters;

public:

	//начало конструкторов
	struct_dissociaty() {
		name_alter = "none";
		function_alter = "none";
	}

	struct_dissociaty(std::string name, std::string func)
		: name_alter(std::move(name)), function_alter(std::move(func)) {
	}

	//конец конструкторов

	//методы доступа
	void setAlters(std::string n, std::string f) {
		function_alter = f;
		name_alter = n;
	}

	void alter_info() {
		callCounter++;
		std::cout << "Call: " << callCounter << " | Name: " << name_alter
			<< " | Function: " << function_alter << std::endl;
	}

	//сохранение в файл

	void saveToFile(std::ofstream& file) const {
		file << name_alter << "|" << function_alter << "\n";
	}

	//статичные методы 

	static void addAlter(const std::string& name, const std::string& func) {
		all_alters.emplace_back(name, func);
	}

	static void showAlter() {
		for (auto& list : all_alters)
			list.alter_info();
	}

	static void saveAllToFile(const std::string& filename) {
		std::ofstream file(filename);
		if (!file) return; // проверка открыт файл или нет

		for (auto& alter : all_alters) {
			alter.saveToFile(file);
		}

		std::cout << "Saved to " << filename << std::endl;
	}

	static void loadFromFile(const std::string& filename) {
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
						struct_dissociaty::removeFile(filename); 
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
				addAlter(name, func);
			}

		}
		struct_dissociaty::showAlter();
	}

	static void removeFile(const std::string& filename) {
		std::filesystem::path p(filename);

		if (std::filesystem::exists(p)) {
			std::filesystem::remove(p);
			std::cout << "[System] file " << filename << "deleted successfully\n";
		}
		else {
			std::cout << "[Error] can't delete: file " << filename << "not find\n";
		}
	}
};

std::vector<struct_dissociaty> struct_dissociaty::all_alters;

int main() {
	struct_dissociaty::loadFromFile("alters.txt");
	std::string name;
	std::string func;
	int count;

	while (true) {

		std::cout << "count: ";
		std::cin >> count;
		std::cin.ignore();
		if (count <= 0) break;
		std::cout << "[Error] count need be positive. " << std::endl;

	}

	for (int i = 0; i < count; i++) {
		std::cout << "\nAlter # " << i + 1 << ":\n";

		std::cout << "Name: ";
		std::getline(std::cin, name);
		std::cout << "Func: ";
		std::getline(std::cin, func);

		struct_dissociaty::addAlter(name, func);
	}


	std::cout << "\n--- All alters ---\n";
	struct_dissociaty::showAlter();

	char ch;
	std::cout << "\n save? (y/n): ";
	std::cin >> ch;

	while (true) {

		if (ch == 'y' || ch == 'Y') {
			struct_dissociaty::saveAllToFile("alters.txt"); break;
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
