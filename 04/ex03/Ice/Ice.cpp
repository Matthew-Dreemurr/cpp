#include "Ice.hpp"
#include "../ICharacter/ICharacter.hpp"

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

void AMateria::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}