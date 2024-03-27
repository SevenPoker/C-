
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

	// 사용자 정의 타입을 컨테이너 보관할 수 있지만
	// 알고리즘 사용시에는 알고리즘의 요구조건을 충족해야한다.
	// => std::sort() 사용하기 위해서는 크기비교를 할 수 있어야한다.

	// std::sort(v.begin(), v.end()); //error

	// #1. 람다표현식으로 비교정책 전ㄴ달.
	std::sort(v.begin(), v.end(), 
				[](const Point& p1, const Point& p2){return p1.x < p2.x;});

	// #2. Point 타입 자체의 크기 비교가 가능하면 된다.
	
}




