#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
	protected:
		std::string **ideas;
	public:
		Brain(void);
		Brain(const Brain &);
		Brain* operator=(const Brain &);
		~Brain(void);
};

#endif /* BRAIN_H */
