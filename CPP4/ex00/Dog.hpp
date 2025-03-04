#pragma	once
#include "Animal.hpp"

class Dog: virtual public Animal
{
	public:
	Dog();
	Dog(const Dog& other);
	~Dog();
	Dog&	operator=(const Dog& other);

	void	makeSound(void);
};
