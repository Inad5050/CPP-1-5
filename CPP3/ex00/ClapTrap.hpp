#include <iostream>

class	ClapTrap
{
	private:
	std::string	name;
	int			HitPoints;
	int			EnergyPoints;
	int			AttackDamage;

	public:
	ClapTrap(std::string std): name(std), HitPoints(10), EnergyPoints(10), AttackDamage(0) 
	{
		std::cout << "Constructor called" << std::endl;
	};

	~ClapTrap()
	{
		std::cout << "Destructor called" << std::endl;
	};

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	int		checkStatus() const;
};