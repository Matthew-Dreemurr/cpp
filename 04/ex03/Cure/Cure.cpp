#include "Cure.hpp"
#include "../ICharacter/ICharacter.hpp"

Cure::Cure()
: AMateria("cure")
{
}

Cure::Cure(const Cure & newIce)
: AMateria(newIce.type)
{
}

Cure::~Cure() {
}

Cure* Cure::clone() const {
	return (new Cure(*this));
}

void AMateria::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}