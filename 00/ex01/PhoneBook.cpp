//
// Created by fluffy on 1/6/23.
//

#include "PhoneBook.hpp"
#include "iomanip"
#include <stdlib.h>
#include <cstdio>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}
PhoneBook::PhoneBook(const PhoneBook &newPhoneBook) {
	// Copy all public attribute
	*this = newPhoneBook;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &newPhoneBook) {
	// Copy all contact
	for (size_t i = 0; i < 8; i++)
		this->contact[i] = newPhoneBook.contact[i];
	// Return it self
	return *this;
}

int		PhoneBook::promptCommand() {
	while (1)
	{	
		// Get command
		if (this->ask("PHONEBOOK$ "))
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
		} else if (this->commandInput == "SEARCH") {
			if (this->selectContact())
				return (EXIT_SUCCESS);
		} else if (this->commandInput == "EXIT") {
			return (EXIT_SUCCESS);
		}
	}
}

bool	PhoneBook::ask(std::string promptMessage) {
	this->commandInput.clear();
	do {
		std::cout << promptMessage;

		// Read the stdin
		std::cin.clear();
		getline(std::cin, this->commandInput);

		// Check if the stdin was not close
		if (std::cin.eof() || std::cin.fail() || !std::cin.good())
		{
			// Try to reset the stream
			std::cin.clear();
			std::cin.ignore();

			// Check if the reset work
			if (std::cin.fail() || !std::cin.good())
				return (EXIT_FAILURE);
			// If the stdin work retry the prompt
			continue ;
		}
	// Do while the command input is empty or if there is only white space
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
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|NICKNAME  |" << std::endl;
	std::cout << "0==========0==========0==========0==========0" << std::endl;
	for (int index = 0; index < 8; index++) {
		std::cout << "|" << std::right << std::setw(10) << index << "|";
		std::cout << std::right << std::setw(10) << truncateString(this->contact[index].firstName) << "|";
		std::cout << std::right << std::setw(10) << truncateString(this->contact[index].lastName) << "|";
		std::cout << std::right << std::setw(10) << truncateString(this->contact[index].nickName) << "|";
		std::cout << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
}

void	PhoneBook::printContact(int index) {
	if (index < 0 || index > 7)
		return ;
	
	std::cout << "First Name: " << this->contact[index].firstName << std::endl;
	std::cout << "Last Name: " << this->contact[index].lastName << std::endl;
	std::cout << "Nick Name: " << this->contact[index].nickName << std::endl;
	std::cout << "Phone Number: " << this->contact[index].phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->contact[index].darkestSecret << std::endl;
}

bool	PhoneBook::selectContact() {
	this->printContacts();

	int index;

	while (1)
	{
		if (this->ask("Select contact: "))
			return (EXIT_FAILURE);
		
		// Convert string to int
		std::sscanf(this->commandInput.c_str(), "%d", &index);
		if (index < 0 || index > 7) {
			std::cout << "Bad index, please retry" << std::endl;
			continue ;
		}
		break ;
	}
	this->printContact(index);
	return (EXIT_SUCCESS);
}