#include <vector>
#include "show.h"

// 컨테이너의 "Primitive type (int, double등)" 이 아닌
// => 사용자 정의 타입을 보관할때 주의 할 점.

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// #1. 디폴트 생성자가 없는 타입
	// std::vector<Point> v(10); // error
	std::vector<Point> v(10, Point(0,0)); // ok

	// v.resize(20); // errror	
	v.resize(20,Point(0,0)); // ok

	v.resize(5,Point(0,0)); // 견본이 되는 객체가 있어야 된다.
}

// C++ IDioms 에서 "Generic Container Idioms" 참고
// => 컨테이너를 만들때는 저장하는 요소에 대해서 최소한의 요구조건만 가져야한다.
// => STL 컨테이너는 "복사생성자" 와 "예외가 없는 소멸자"만 있다면 모두 저장 가능하다.

