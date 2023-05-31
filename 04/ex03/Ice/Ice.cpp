#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{
}

Ice::Ice(const Ice & newIce)
: AMateria(newIce.type)
{
}

Ice::~Ice() {
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}
