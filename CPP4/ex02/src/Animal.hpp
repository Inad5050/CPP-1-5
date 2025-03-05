#pragma	once
#include <iostream>

class Animal
{
	protected:
		std::string	type;
		Animal();
		Animal(const std::string type);
		Animal(const Animal& other);

	public:
		virtual ~Animal();
		Animal&	operator=(const Animal& other);

		const std::string&	getType() const;
		virtual void		makeSound() const;
};
