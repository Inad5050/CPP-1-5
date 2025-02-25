#pragma	once

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private:
	std::string	name;	
	Weapon&		_Weapon;

	public:
	HumanA(std::string new_name, Weapon &new_Weapon) : name(new_name), _Weapon(new_Weapon) {}; 
	~HumanA() {};
	void	attack();	
};
