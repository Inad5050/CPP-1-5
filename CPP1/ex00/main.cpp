#include <Zombie.hpp>

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	
	std::string	name1 = argv[1];
	std::string	name2 = argv[2];

	Zombie*	heap_zombie = newZombie(name1);
	delete heap_zombie;
	
	randomChump(name2);

	return (0);
}
