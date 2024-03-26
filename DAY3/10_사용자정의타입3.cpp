
#include <vector>
#include <algorithm>
#include "show.h"
class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }

	Point(const Point& p)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
	void dump() const 
	{
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	std::vector<Point> v;

	v.emplace_back(1, 2); // Point(1,2)
	v.emplace_back(2, 3);
	v.emplace_back(3, 2);
	v.emplace_back(0, 1);

	std::sort(std::begin(v), std::end(v));

}




