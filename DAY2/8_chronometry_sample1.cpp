#include "chronometry.h"
#include <thread>
#include <string_view>
using namespace std::literals;

void f1()
{
	std::this_thread::sleep_for(3s);
}

void f2(int a, double d)
{
	std::this_thread::sleep_for(2s);
}

int f3(int a, std::string_view sv)
{
	return a + 10;
}

int main()
{	
	// chronometry : 함수의 수행 시간을 측정하는 함수

	// chronometry 사용법
	// chronometry( 함수이름(주소) )
	// chronometry( 함수이름(주소), argument1, argument2, ...  )

	chronometry(f1);			// f1() 의 수행시간 측정
	chronometry(f2, 1, 3.4);	// f2(1, 3.4)

	int ret = chronometry(f3, 1, "aaa"); // int ret = f3(1, "aaa"); 
}