#include "harlfilter.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << MSG_DEBUG << std::endl << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << MSG_INFO << std::endl << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << MSG_WARNING << std::endl << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << MSG_ERROR << std::endl << std::endl;
}

void Harl::complain(std::string level) {

	const std::string findLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (findLevel[i] == level) {
			index = i;
			break;
		}
	}

	switch (index) {
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
	}
}
