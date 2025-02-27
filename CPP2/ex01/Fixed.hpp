#include <iostream>

class Fixed
{
	private:
	int	number;
	static const int	fractional_bits = 8; //const: value cant change after being initialized. static: the variable belongs to the class and not to this particular instance of the class

	public:

	Fixed::Fixed(): number(0)
	{
		std::cout << "Default constructor called" << std::endl;
	}

	Fixed::Fixed(const int input): number(input << fractional_bits) //new constructor
	{
		std::cout << "Int constructor called" << std::endl;
	}

	Fixed::Fixed(const float input): number(input * (1 << fractional_bits)) //new constructor
	{
		std::cout << "Float constructor called" << std::endl;
	}

	Fixed::Fixed(const Fixed& other): number(other.number) //copy constructor
	{
		std::cout << "Copy constructor called" << std::endl;
	}

	Fixed::~Fixed() 
	{
		std::cout << "Destructor called" << std::endl;
	}

	//In the context of a C++ class, an operator is a special function that allows you to define how operators (such as +, -, =, ==, etc.) work for instances of your class. This is known as operator overloading. By overloading operators, you can provide custom behavior for operations involving objects of your class.
	//copy assignment operator overload. Copy assignment operator: This operator first checks that the object is not being assigned to itself (this is called "self-assignment"). If it is not self-assignment, it copies the value of number from the other object and returns a reference to the current Fixed object.
	//this will execute when we execute Fixed a = Fixed b;
	Fixed&	operator=(const Fixed& other);

	int		getRawBits(void) const; //when method functions are declared as constant the wont change the values of private or public variables in their class
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	friend	std::ostream& operator<<(std::ostream& os, const Fixed& fixed); //a friend function is not a member, bus has acces to the private variables of a class. They are often used to overcharge operators
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)	//converts our output to float on the ostream so that we can print it
{
    os << fixed.toFloat();
    return (os);
}
