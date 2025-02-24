#include <Zombie.hpp>

void	randomChump(std::string& name) //aloja el zombie en el stack
{
	Zombie	random_zombie(name);
	random_zombie.announce();
}
