#include <iostream>
#include <fstream>
#include <string>

bool fileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.is_open();
}


int _count(std::string file_name) {
	std::ifstream file1(file_name);
	int ID = 0;
	std::string string;

	if (file1.is_open()) {
		while (std::getline(file1, string)) {
			ID += 1;
		}
	}
	return ID;
}

void file_read(std::string file_name) {
	int ID = 0, amount = 0, amount_of_str = 0, place = 0;
	std::string name, string, word;
	float cost = 0;




	std::ifstream file1;
	file1.open(file_name);

	if (file1.is_open()) {
		while (std::getline(file1, string)) {
			ID += 1;
			for (int i = 0; i < std::size(string); i++) {
				if (string[i] != '|') {
					word = word + string[i];
				}
				else {
					if (place == 0) { name = word; }
					if (place == 1) { amount = stoi(word); }
					if (place == 2) { cost = stof(word); }
					place += 1; word = "";

				}
			}
			std::cout << ID << ")\t" << name << "\t" << amount << "\t" << cost << "\n";
			word = "";
			place = 0;
		}
	}
	else {
		std::cout << "a problem has occured, file weren't opened";
	}





}
void file_write(std::string file_name) {
	int choice, ID, amount;
	std::string name;
	float cost;
	std::ifstream file1_read;
	std::ofstream file1;

	file1_read.open(file_name);


	if (_count(file_name) != 0) {

		do {
			std::cout << "Do you want to\n1 - Rewrite\n2 - Add\n>>> ";
			std::cin >> choice;
			system("cls");
		} while (choice < 1 || choice > 2);

		if (choice == 1) {
			file1.open(file_name);

		}
		else if (choice == 2) {
			file1.open(file_name, std::ofstream::app);
		}
	}
	else {
		file1.open(file_name);
	}


	if (file1.is_open()) {
		std::cout << "file succesfully opened!";
	}
	else {
		std::cout << "a problem has occured, file weren't opened";
	}


	choice = NULL;


	do {
		std::cout <<
			"What do you want to write?\n1 - Pre-made example[like in the task]\n2 - Your own thing\n>>> ";
		std::cin >> choice;
		system("cls");
	} while (choice < 1 || choice > 2);

	if (choice == 1) {
		file1 << "Cake1|15|30|\nCake2|15|30|\nCake3|15|30|\n";
		std::cout << "Information were succesfuly added!";
	}
	if (choice == 2) {
		std::cout << "Enter the name of the product: ";
		///std::cin >> name;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, name);
		std::cout << "Enter the cost of the product: ";
		std::cin >> cost;
		std::cout << "Enter the amount of product: ";
		std::cin >> amount;
		file1 << name << "|" << cost << "|" << amount << "|\n";
		system("cls");
		std::cout << "Product were succesfuly added!";
	}
}



int main() {
	int file_choice = -1, action_choice = -1;
	std::string file_names[3]{ "file1.txt", "file2.txt", "file3.txt" }, file_name;

	while (true) {
		do {
			std::cout << "Choose file:\n";
			for (int i = 0; i < 3; i++) {
				std::cout << i + 1 << " - " << file_names[i] << "\n";
			}
			std::cout << ">>> ";
			std::cin >> file_choice;
			file_name = file_names[file_choice - 1];
			system("cls");
		} while (file_choice < 1 || file_choice >3);

		do {
			std::cout << "Choose an action:\n1 - Read\n2 - Write\n>>> ";
			std::cin >> action_choice;
			system("cls");
		} while (action_choice < 1 || action_choice > 2);

		if (action_choice == 1) {
			file_read(file_name);
		}
		else if (action_choice == 2) {
			file_write(file_name);
		}
	}
	return 0;
}