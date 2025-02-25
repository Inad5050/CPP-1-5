#pragma	once

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
	std::string	name;
	Weapon*		_Weapon;

	public:
	HumanB(std::string	new_name) : name(new_name), _Weapon(NULL) {}; 
	~HumanB() {};
	void	attack();
	void	setWeapon(Weapon weaponName);
};
