#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Generic dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy dog constructor called" << std::endl;
	type = other.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "Dog makeSound called: MIAAAU!" << std::endl;
}
