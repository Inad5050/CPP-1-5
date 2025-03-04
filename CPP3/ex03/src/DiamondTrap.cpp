#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	HitPoints = ScavTrap::HitPoints;
}

DiamondTrap::DiamondTrap(std::string str): ClapTrap(str + "_clap_name"), name(str)
{
	std::cout << "DiamondTrap constructor called!" << std::endl;
	HitPoints = FragTrap::HitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	HitPoints = ScavTrap::HitPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other.name + "_clap_name")
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	HitPoints = other.HitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDamage = other.AttackDamage;
	HitPoints = other.HitPoints;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy operator called!" << std::endl;
	if (this != &other)
	{
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
		HitPoints = other.HitPoints;	
	}
	return (*this);
}

void	DiamondTrap::WhoAmI()
{
	std::cout << "I am " << name << " son of " << ClapTrap::name << "!" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap attack called!" << std::endl;
	ScavTrap::attack(target);
}
