#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void foo(int a) {}
	void goo(int a, int b) {}
};

int main()
{
	// std::function : 함수 포인터를 일반화한 클래스 템플릿
	// 사용법 : std::function<함수타입>
	
	// void(*)(int) : 함수 포인터 타입
	// void(int)    : 함수 타입

	std::function<void(int)> f;

}


