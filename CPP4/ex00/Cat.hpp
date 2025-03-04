#pragma	once
#include "Animal.hpp"

class Cat: virtual public Animal
{
	public:
	Cat();
	Cat(const Cat& other);
	~Cat();
	Cat&	operator=(const Cat& other);

	void	makeSound(void);
};
