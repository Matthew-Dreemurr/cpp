//
// Created by fluffy on 1/6/23.
//

#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

#include "iostream"
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook		();
	~PhoneBook		();
	PhoneBook		(const PhoneBook&);
	PhoneBook&		operator=(const PhoneBook&);

void		promptCommand	();
std::string	ask				(std::string promptMessage);
private:
	Contact		contact[8];
	std::string	tmpInput;
};


#endif //CPP_PHONEBOOK_HPP
