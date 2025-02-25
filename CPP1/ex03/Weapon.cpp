#include "Weapon.hpp"

std::string	Weapon::getType() const
{
	return (Weapon::type);
}

void	Weapon::setType(std::string newWeapon)
{
	Weapon::type = newWeapon;
}
