#include "SedisForLosers.hpp"

int	main(void)
{
	std::string	fileName;
	std::string	str1;
	std::string	str2;

	std::cout << "Give me a fileName" << std::endl;
	if (!(std::cin >> fileName))
		return (std::cerr << "Incorrect paramater, exiting." << std::endl, 1);
	std::cout << "Give me a string" << std::endl;
	if (!(std::cin >> str1))
		return (std::cerr << "Incorrect paramater, exiting." << std::endl, 1);
	std::cout << "Give me another string" << std::endl;
	if (!(std::cin >> str2))
		return (std::cerr << "Incorrect paramater, exiting." << std::endl, 1);

	if (SedisForLosers(fileName, str1, str2))
		return (1);

	return (0);
}