#include "Point.hpp"


Point::Point(): x(0), y(0)
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point(float x, float y): x(x), y(y)
{
	std::cout << "Point constructor called" << std::endl;
}

Point::Point(Point& other): x(other.x), y(other.y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Point& Point::operator=(Point& other)
{
	std::cout << "Point copy operator called" << std::endl;
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

