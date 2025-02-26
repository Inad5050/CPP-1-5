#include "Harl.hpp"

void	debug(void)
{
	std::cout << "Debug message" << std::endl;
}
void	info(void)
{
	std::cout << "Info message" << std::endl;
}
void	warning(void)
{
	std::cout << "Warning message" << std::endl;
}	
void	error(void)
{
	std::cout << "Error message" << std::endl;
}	

void	complain(std::string level)
{
	Harl	private_functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}




}