#include <vector>
#include "show.h"

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }
	
	Point(const Point& p)
	{
		std::cout << "Point(const Point&) - copy" << std::endl;
	}
	
	Point(Point&& p)
	{
		std::cout << "Point(Point&&) - Move" << std::endl;
	}
};
int main()
{
	std::vector<Point> v;

	// 실행결과 예측해 보세요
	// 1. 객체를 생성후 넣기.
//	Point pt(1, 2); // stack에 생성된다.
//	v.push_back(pt); 
	// heap 영역에 있기 때문에 위의 Point를 복사해서 heap에 만든다.
	// (1) Point pt 생성자호출
	// (2) heap에 복사
	// (3) Point pt 소멸자 호출
	// (4) heap 쪽 소멸자 호출

	// #2. 임시객체 형태로 넣기
//	v.push_back( Point(1,2));
	// move가 불린다.

	// #3. 임시객체를 만드는 또다른 표기법
//	v.push_back({1,2}); // C++11 부터 가능한 표기법

	// #4. 객체를 전달하지 말고, 객체를 만들기 위한 생성자 인자만 전달하고
	// 니가 알아서 만들어라!!!
	// 객체로 넘겼을때는 생성자를 만들어야 되기 때문에 그냥 emplace를 써라

	v.emplace_back(1,2);
	// vector가 내부적으로 자신의 버퍼에 new Point(1,2) 를 수행한다.

	std::cout << "------------------" << std::endl;	
}

// 사용자 정의 타입을 보관한다면 "push_xxx" 대신에 "emplace_xxx"
// push_back을 대신하는것이 emplace_back이다
// push_front를 대신다는것이 emplace_front이다
// insert를 대신하는것이 emplace 이다.

// 단, primitive 타입 (int, double ...) 또는 usertype* 인 경우는
// 두개가 비슷하다.

// vector<int>
// vector<Point*>

