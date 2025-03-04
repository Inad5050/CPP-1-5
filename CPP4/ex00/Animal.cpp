#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Generic animal constructor called" << std::endl;
	type = "generic animal";
}

Animal::Animal(const std::string type): type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy animal constructor called" << std::endl;
	type = other.type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	std::string	str1 = "I am a " + type;
	return (str1);
}

