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
			PhoneBook		&operator=(const PhoneBook&);
	void	printContacts	();
	void	printContact	(int index);
	bool	selectContact	();
	int		promptCommand	();
private:
	bool		ask				(std::string promptMessage);
	Contact		contact[8];
	std::string	truncateString	(std::string &string);
	std::string	commandInput;
};


#endif //CPP_PHONEBOOK_HPP
