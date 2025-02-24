#include <iostream>

/* int	main(int argc, char **argv)
{
	int	y = 1;
	int	x;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		x = 0;
		while (argv[y][x])
		{
			if ('a' <= argv[y][x] && argv[y][x] <= 'z')
				std::cout << static_cast<char>(argv[y][x++] - 32);
			else
				std::cout << static_cast<char>(argv[y][x++]);
		}
		y++;
	}
	std::cout << "\n";
	return 0;
} */

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int y = 1; argv[y]; y++)
			for (int x = 0; argv[y][x]; x++)
				std::cout << static_cast<char>(toupper(argv[y][x]));
	}
	std::cout << "\n";
	return (0);
}
