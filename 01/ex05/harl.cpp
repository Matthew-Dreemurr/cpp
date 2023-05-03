#include "harl.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void Harl::debug(void) {
	std::cout << MSG_DEBUG << std::endl;
}

void Harl::info(void) {
	std::cout << MSG_INFO << std::endl;
}

void Harl::warning(void) {
	std::cout << MSG_WARNING << std::endl;
}

void Harl::error(void) {
	std::cout << MSG_ERROR << std::endl;
}

void Harl::complain(std::string level) {

	const std::string findLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (*functionPtr[])() = {
			debug,
			info,
			warning,
			error,
			NULL
		};

	for (size_t i = 0; functionPtr[i]; i++)
	{
		if (findLevel[i] == level) {
			(functionPtr[i])();
			break;
		}
	}
}
