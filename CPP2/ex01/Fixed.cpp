#include "Fixed.hpp"

Fixed&	Fixed::operator=(const Fixed& other)
{										
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->number = other.number;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}

float	Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
	return (static_cast<float>(this->number) / (1 << fractional_bits)); //On CPP there isnt an inplicit cast if the function output is a float we have to cast it manually with static_cast<data_type>(to_cast_value)
}

int		Fixed::toInt(void) const
{
	std::cout << "toInt member function called" << std::endl;
	return (this->number >> this->fractional_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) //converts our output to float on the ostream so that we can print it
{
    os << fixed.toFloat();
    return (os);
}
