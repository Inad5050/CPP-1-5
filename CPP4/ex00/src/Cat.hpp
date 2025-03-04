#pragma	once
#include "Animal.hpp"

class Cat: public Animal
{
	public:
	Cat();
	Cat(const Cat& other);
	~Cat();
	Cat& operator=(const Cat& other);

	virtual void makeSound(void) const;
};
