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
		std::string tmp = this->ask("UwU?");
		std::cout << tmp << "\n";
}

std::string	PhoneBook::ask(std::string promptMessage) {
	std::cout << promptMessage << ": ";
	std::cin >> this->tmpInput;
	return this->tmpInput;
}