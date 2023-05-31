#ifndef ICE_H
#define ICE_H

#include "AMateria/AMateria.hpp"

class Ice: public AMateria
{
private:

public:
	Ice();
	Ice(const Ice &);
	~Ice();
	Ice* clone() const;
};

#endif /* ICE_H */
