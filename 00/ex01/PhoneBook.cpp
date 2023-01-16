//
// Created by fluffy on 1/6/23.
//

#include "PhoneBook.hpp"
#include "iostream"
#include "iomanip"

PhoneBook::PhoneBook() {

}
PhoneBook::~PhoneBook() {}
PhoneBook::PhoneBook(const PhoneBook &) {}

void		PhoneBook::promptCommand() {
	// Get command
	this->ask("PHONEBOOK$");

	// Exe the command
	if (this->commandInput == "ADD") {
		std::cout << "## ADD\n";

		// Move all contact down
		for (int index = 7; index > 0; index--) {
			this->contact[index] = this->contact[index - 1];
		}

		// Add new contact with the user input
		this->contact[0].addContact();
		this->printContacts();
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
	} while (this->commandInput.empty() || commandInput.find_first_not_of (' ') == commandInput.npos);
}

std::string	PhoneBook::truncateString(std::string &string)
{
	if (string.length() > 10)
		return string.substr(0, 9) + ".";
	return string;
}

void	PhoneBook::printContacts() {
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|NICKNAME |\n";
	for (int index = 0; index < 8; index++) {
		std::cout << "|" << std::right << std::setw(10) << index << "|";
		std::cout << std::right << std::setw(10) << truncateString(this->contact[index].firstName) << "|";
		std::cout << std::right << std::setw(10) << truncateString(this->contact[index].lastName) << "|";
		std::cout << std::right << std::setw(10) << truncateString(this->contact[index].nickName) << "|";
		std::cout << "\n";
	}
}