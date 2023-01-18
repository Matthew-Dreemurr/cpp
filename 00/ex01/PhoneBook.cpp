//
// Created by fluffy on 1/6/23.
//

#include "PhoneBook.hpp"
#include "iomanip"
#include <stdlib.h>

PhoneBook::PhoneBook() {

}
PhoneBook::~PhoneBook() {}
PhoneBook::PhoneBook(const PhoneBook &) {}

int		PhoneBook::promptCommand() {
	// Get command
	if (this->ask("PHONEBOOK$"))
		return (EXIT_SUCCESS);

	// Exe the command
	if (this->commandInput == "ADD") {

		// Move all contact down
		for (int index = 7; index > 0; index--) {
			this->contact[index] = this->contact[index - 1];
		}

		// Add new contact with the user input
		if (this->contact[0].addContact())
			return (EXIT_SUCCESS);
		this->printContacts();
	} else if (this->commandInput == "SEARCH") {
		std::cout << "## SEARCH\n";
	} else if (this->commandInput == "EXIT") {
		std::cout << "## EXIT\n";
        return (EXIT_SUCCESS);
	}
	std::cout << this->commandInput << "\n";
    return (2);
}

bool	PhoneBook::ask(std::string promptMessage) {
	this->commandInput.clear();
	do {
		std::cout << promptMessage << ": ";
		std::cin.clear();
		getline(std::cin, this->commandInput);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			if (std::cin.fail() || !std::cin.good())
				return (EXIT_FAILURE);
			continue ;
		}
	} while (this->commandInput.empty() || commandInput.find_first_not_of (' ') == commandInput.npos);
	return (EXIT_SUCCESS);
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
		std::cout << std::endl;
	}
}