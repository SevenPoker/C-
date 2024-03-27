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
	// 힙에 객체 한개 생성
	Point* p1 = new Point(1,2);

	// 힙에 객체 10개 만들어보세요.
	Point* p2 = new Point[10]; // error. 10개의 디폴트 생성자 호출이 필요한데
							   // 디폴트 생성자가 없다.

	// 메모리 할당과 생성자 호출을 분리하면 유연성이 좋다.
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point) * 10));
	// 메모리를 할당했다.

	//할당된 메모리에 객체를 생성해보자
	for (int i = 0; i < 10; i++)
	{
		new(&p[i]) Point(0,0);
	}

	// 생성자를 파괴하는 소멸자도 호출해줘야한다.
	for (int i = 0; i < 10; i++)
	{
		p[i].~Point();
	}

	// 메모리를 해제해줘야한다.
	operator delete(p2);

} 
