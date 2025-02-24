#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	PB;
	std::string	input;

	std::cout <<	std::endl <<
					"//////////////////////////" << std::endl <<
					"///     PHONE BOOK     ///" << std::endl <<
					"//////////////////////////" << std::endl << std::endl;

	while(1)
	{
		if (std::cin.eof())
			return(std::cout << "EOF: Input stream closed" << std::endl, 0);
		std::cout << "Enter command (ADD, SEARCH or EXIT): " << std::endl;
		if (!std::getline(std::cin, input))
			break;
		else if (input == "ADD")
			(PB.add_contact());
		else if (input == "SEARCH")
		{
			if (PB.search_contact())
				continue;
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Incorrect command" << std::endl;
	}
	return (0);
}