#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Generic cat constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy cat constructor called" << std::endl;
	type = other.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "Cat makeSound called: MIAAAU!" << std::endl;
}
