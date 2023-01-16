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

void	promptCommand	();
private:
	void		ask			(std::string promptMessage);
	Contact		contact[8];
	std::string	commandInput;
};


#endif //CPP_PHONEBOOK_HPP
