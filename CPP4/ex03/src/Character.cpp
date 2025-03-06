#include "Character.hpp"

Character::Character(): name("Default name")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(std::string name): name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(Character& other): name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = new AMateria(*other.inventory[i]);
}

Character::~Character()
{
	std::cout << "Character destrcutor called" << std::endl;
}

Character& Character::operator=(Character& other)
{
	std::cout << "Character copy operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		delete[] inventory;
		for (int i = 0; i < 4; i++)
			inventory[i] = new AMateria(*other.inventory[i]);
	}
	return (*this);
}

std::string const & Character::getName() const
{
	std::cout << "Character getName() called. My name is: " << name << "!" << std::endl;
}

void Character::equip(AMateria* m)
{
	if (m = nullptr)
		std::cout << "Character equip() called! No materia to equip!" << std::endl;
	else
	{
		int	i;
		for (i = 0; i < 4 && inventory[i] != nullptr; i++)
			inventory[i] = m;
		if (i == 4)
			std::cout << "Character equip() called! No free slots on the inventory!" << std::endl;
	}
}

void Character::unequip(int idx)
{
	std::cout << "haracter equip() called!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << " " << std::endl;
}

