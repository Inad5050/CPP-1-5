#pragma once

#include <iostream>
#include <vector> //push_back (adds a new element at the end of the list), pop_back (deletes the last element), size (returns the vectors size), clear (clears the whole vector)
#include <string>

class Zombie
{
	private:
	std::string	_name;

	void	announce()
	{
		std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}

	public:

	Zombie(std::string& name) : _name(name) {}

	~Zombie() //destructors are called automatically for objects in the stack (when a function finishes for example) or heap (when we use delete)
	{
		std::cout << _name << " has been destroyed." << std::endl;
	}

	Zombie*	newZombie(std::string name) //aloja el zombie en el heap
	{
		Zombie* new_zombie = new Zombie(name); //new assigns enough memory for an specific entity
		new_zombie->announce();
		return (new_zombie);
	}

	void	randomChump(std::string	name) //aloja el zombie en el stack
	{
		Zombie	random_zombie(name);
		random_zombie.announce();
	}
};
