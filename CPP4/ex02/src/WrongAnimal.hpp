#pragma	once
#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& other);

		const std::string&	getType() const;
		void		makeSound() const;
};
