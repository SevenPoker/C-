
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
	// C++20 의 새로운 연산자 (three way comparison, "우주선 연산자" 라는 별명)
	auto ret = 1 <=> 3;

	Point p1(1,2);
	Point p2(3,4);

//	bool b = p1 > p2;

}




