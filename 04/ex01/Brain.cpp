#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "[Brain] Create new Brain with 100 ideas slot" << std::endl;
	this->ideas = new std::string*[100];
}

Brain::~Brain(void) {
	std::cout << "[Brain] Delete Brain and 100 ideas" << std::endl;
	delete [] this->ideas;
}

Brain* Brain::operator=(const Brain& newBrain) {
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = newBrain.ideas[i];
	}
	std::cout << "[Brain] Brain cloned" << std::endl;
	return this;
}