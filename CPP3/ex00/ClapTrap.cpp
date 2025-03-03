#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string& target)
{
	if (checkStatus() != 0)
		return;
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
	EnergyPoints -= 1;
};

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (checkStatus() != 0)
		return;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	EnergyPoints -= 1;
	HitPoints -= amount;
};

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (checkStatus() != 0)
		return;
	std::cout << "ClapTrap " << name << " heals " << amount << " points of damage!" << std::endl;
	EnergyPoints -= 1;
	HitPoints += amount;
};

int ClapTrap::checkStatus() const
{
	if (HitPoints <= 0)
	{
		std::cout << "HitPoints depleted, " << name << " is out of commision!" << std::endl;
		return (1);
	}
	if (EnergyPoints <= 0)
	{
		std::cout << "EnergyPoints depleted, " << name << " is out of commision!" << std::endl;
		return (1);
	}
	return (0); 
};


