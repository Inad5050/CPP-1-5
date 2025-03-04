#include "Fixed.hpp"

Fixed&	Fixed::operator=(const Fixed& other)
{										
	std::cout << "Copy assignment operator called!" << std::endl;
	if (this != &other)
		this->number = other.number;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called!" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called!" << std::endl;
	this->number = raw;
}