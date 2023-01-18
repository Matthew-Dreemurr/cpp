//
// Created by fluffy on 1/6/23.
//

#include "Contact.hpp"
#include <stdlib.h>

Contact::Contact() {}
Contact::Contact(const Contact &newContact) {
	*this = newContact;
}
Contact::~Contact() {}
Contact &Contact::operator=(const Contact &newContact) {
	this->firstName = newContact.firstName;
	this->lastName = newContact.lastName;
	this->nickName = newContact.nickName;
	this->phoneNumber = newContact.phoneNumber;
	this->darkestSecret = newContact.darkestSecret;
	return *this;
}

bool	Contact::ask(std::string promptMessage, std::string &data) {
	this->commandInput.clear();
	data.clear();
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
	data = commandInput;
	return (EXIT_SUCCESS);
}

int	Contact::addContact() {
	if (
	this->ask("First Name: ", this->firstName) ||
	this->ask("Last Name: ", this->lastName) ||
	this->ask("Nick Name: ", this->nickName) ||
	this->ask("Phone Number: ", this->phoneNumber) ||
	this->ask("Darkest Secret: ", this->darkestSecret))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}