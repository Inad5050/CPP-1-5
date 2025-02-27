#include "Harl.hpp"
#include <limits>

int	main(void)
{
	std::string	input;
	Harl		mrHarl;

	while (1)
	{
		std::cout << "Enter: DEBUG, INFO, WARNING or ERROR" << std::endl;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				return (1);
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max());
				std::cout << "Invalid input" << std::endl;
			}
		}
		else
			mrHarl.complain(input);
	}	
	return (0);
}
