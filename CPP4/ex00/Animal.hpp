#pragma	once
#include <iostream>

class Animal
{
	protected:
	std::string	type;

	public:
	Animal();
	Animal(const std::string type);
	Animal(const Animal& other);
	~Animal();
	Animal&	operator=(const Animal& other);

	std::string	Animal::getType(void) const;
};
