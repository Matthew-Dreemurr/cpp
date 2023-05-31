#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
class AMateria
{
	protected:
		//[...]
		std::string type;
	public:
		AMateria(std::string const & type);
		//[...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif /* AMATERIA_H */
