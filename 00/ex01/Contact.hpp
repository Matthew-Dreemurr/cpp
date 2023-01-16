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

	void		setFirstName		(std::string	firstName);
	void		setLastName			(std::string	LastName);
	void		setNickName			(std::string	nickName);
	void		setPhoneNumber		(std::string	phoneNumber);
	void		setDarkestSecret	(std::string	darkestSecret);

	std::string	getFirstName		();
	std::string getLastName			();
	std::string getNickName			();
	std::string getPhoneNumber		();
	std::string getDarkestSecret	();
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};


#endif //CPP_CONTACT_HPP
