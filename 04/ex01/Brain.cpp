#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "[Brain] Create new Brain with 100 ideas slot" << std::endl;
	this->ideas = new std::string*[100];
}

Brain::~Brain(void) {
	std::cout << "[Brain] Delete Brain and 100 ideas" << std::endl;
	delete [] this->ideas;
}