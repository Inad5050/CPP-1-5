#include <iostream>
#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << HumanB::name << " attacks with their " << HumanB::_Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weaponName)
{
	this->_Weapon = &weaponName;
}
