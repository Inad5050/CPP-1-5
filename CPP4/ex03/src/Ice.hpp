#pragma once
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
		



	public:

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
