#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}

int main()
{
	// C언어의 함수 포인터는 유연성이 부족합니다.
    void(*f)(int) = &f1; // ok
	f1 = &f2; 			 // error    
}


