#include <iostream>
#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << HumanA::_Weapon.getType() << std::endl;
}
