#pragma	once

#include <iostream>

class	Weapon
{
	private:
	std::string	type;

	public:
	Weapon() {};
	Weapon(std::string weaponName) : type(weaponName) {};
	~Weapon() {};
	std::string		getType() const;
	void			setType(std::string newWapon);
};