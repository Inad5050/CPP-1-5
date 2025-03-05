#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default AMateria constrcutor called" << std::endl;	
}

AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << "AMateria constrcutor called" << std::endl;	
}

AMateria::AMateria(AMateria& other)
{
	std::cout << "AMateria copy constructor called" << std::endl;	
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;	
}

AMateria& AMateria::operator=(AMateria& other)
{
	std::cout << "AMateria copy operator called" << std::endl;	
}

std::string const & AMateria::getType() const
{
	std::cout << "AMateria gettype called" << std::endl;	
}

AMateria* AMateria::clone() const
{
	std::cout << "AMateria clone called, ERROR: this is a pure virtual member function" << std::endl;	
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use called, ERROR: this is a virtual member function" << std::endl;	
}
