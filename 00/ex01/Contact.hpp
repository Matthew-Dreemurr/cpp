//
// Created by fluffy on 1/6/23.
//

#ifndef CPP_CONTACT_HPP
#define CPP_CONTACT_HPP

#include "iostream"

class Contact {

public:
	Contact		();
	~Contact	();
	Contact		(const Contact&);
	Contact		&operator=(const Contact&);

	int		addContact		();
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
private:

	bool		ask	(std::string promptMessage, std::string &data);
	std::string	commandInput;
};


#endif //CPP_CONTACT_HPP
