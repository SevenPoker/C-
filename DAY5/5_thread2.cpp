#include <iostream>
#include <thread> 

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
	// #1. thread 생성
	f1();

	// #2. 인자 전달
}


