#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] != nullptr;

}

MateriaSource::MateriaSource(std::string)
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] != nullptr;
}

MateriaSource::MateriaSource(MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] == nullptr)
			continue;
		else if ((other.inventory[i]->getType()).compare("ice") == 0)
			inventory[i] = new Ice();
		else if ((other.inventory[i]->getType()).compare("cure") == 0)
			inventory[i] = new Cure();
		else
		{
			std::cout << "Cannot copy " << other.inventory[i]->getType() << " materia!" << std::endl;
			break;
		}
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (inventory[i] != nullptr)
			delete inventory[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource& other)
{
	std::cout << "MateriaSource copy operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			delete inventory[i];		
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] == nullptr)
				continue;
			else if ((other.inventory[i]->getType()).compare("ice") == 0)
				inventory[i] = new Ice();
			else if ((other.inventory[i]->getType()).compare("cure") == 0)
				inventory[i] = new Cure();
			else
			{
				std::cout << "Cannot copy " << other.inventory[i]->getType() << " materia!" << std::endl;
				break;
			}
		}
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria* m)
{
	int	i;
	if (m = nullptr)
	{
		std::cout << "MateriaSource learnMateria() called! No materia to learn!" << std::endl;
		return;
	}
	for (i = 0; i < 4 && inventory[i] != nullptr; i++)
		inventory[i] = m;
	if (i == 4)
		std::cout << "MateriaSource learnMateria() called! No free slots on the inventory!" << std::endl;
	else
		std::cout << "MateriaSource learnMateria() called! " << m->getType() << " materia equiped in slot: " << i << "!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* newMateria;
	for (int i = 0; i < 4; i++)
	{
		if (type.compare(inventory[i]->getType()) == 0)
		{
			if (type.compare("ice") == 0)
				newMateria = new Ice();
			else if (type.compare("cure") == 0)
				newMateria = new Cure();
			std::cout << "MateriaSource createMateria() called! New " << type << " materia created!" << std::endl;
			return (newMateria);
		}
	}
	std::cout << "MateriaSource createMateria() called! Unknown " << type << " materia. No materia created!" << std::endl;
	return (0);
}
