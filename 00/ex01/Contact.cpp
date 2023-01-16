//
// Created by fluffy on 1/6/23.
//

#include "Contact.hpp"

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

std::string	Contact::ask(std::string promptMessage) {
	this->commandInput.clear();
	do {
		std::cout << promptMessage << ": ";
		getline(std::cin, this->commandInput);
	} while (this->commandInput.empty());
	return this->commandInput;
}

void Contact::addContact() {
	this->firstName = this->ask("First Name: ");
	this->lastName = this->ask("Last Name: ");
	this->nickName = this->ask("Nick Name: ");
	this->phoneNumber = this->ask("Phone Number: ");
	this->darkestSecret = this->ask("Darkest Secret: ");
}