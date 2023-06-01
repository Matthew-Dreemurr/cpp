#ifndef CURE_H
#define CURE_H

#include "AMateria/AMateria.hpp"

class Cure: public AMateria
{
private:

public:
	Cure();
	Cure(const Cure &);
	~Cure();
	Cure* clone() const;
};

#endif /* CURE_H */
