#include "DiamondTrap.hpp"

int	main(void)
{
	std::string	str1("Optimus");
	std::string	str2("Megatron");
	DiamondTrap	dia1(str1);

	dia1.WhoAmI();
	dia1.attack(str2);
	dia1.highFivesGuys();
	dia1.guardGate();
	dia1.beRepaired(10);
	dia1.takeDamage(1000);
	dia1.highFivesGuys();
	return (0);
}
