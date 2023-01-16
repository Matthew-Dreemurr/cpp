//
// Created by fluffy on 1/6/23.
//

#include "PhoneBook.hpp"
#include "iostream"

PhoneBook::PhoneBook() {

}
PhoneBook::~PhoneBook() {}
PhoneBook::PhoneBook(const PhoneBook &) {}

void		PhoneBook::promptCommand() {
	this->ask("PHONEBOOK$");
	if (this->commandInput == "ADD") {
		std::cout << "## ADD\n";
		for (int index = 7; index > 0; index--) {
			this->contact[index] = this->contact[index - 1];
		}
		this->contact[0].addContact();
	} else if (this->commandInput == "SEARCH") {
		std::cout << "## SEARCH\n";
	} else if (this->commandInput == "EXIT") {
		std::cout << "## EXIT\n";
	}
	std::cout << this->commandInput << "\n";
}

void	PhoneBook::ask(std::string promptMessage) {
	this->commandInput.clear();
	do {
		std::cout << promptMessage << ": ";
		getline(std::cin, this->commandInput);
	} while (this->commandInput.empty());
}