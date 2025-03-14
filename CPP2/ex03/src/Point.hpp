#include <iostream>

class	Point
{
	private:
	float	x;
	float	y;

	public:
	Point();
	Point(float x, float y);
	Point(Point& other);
	~Point();
	Point&	operator=(Point& other);




};

