#include <iostream>

class Point
{
	int x,y;
public:
	Point(int a, int b) : x(a), y(b) { std::cout << "Point()\n";}
	~Point() { std::cout << "~Point()\n";}
};

int main()
{
	Point *p1 = new Point(1,2);
	delete p1;
}  