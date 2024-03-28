#include <iostream>
#include <string>
#include "show.h"

using namespace std::literals;

void foo(const char* s) { std::cout << "const char*\n";} // 1
void foo(const std::string& s) { std::cout << "string";} // 2

int main()
{
	foo("hello"); // hello의 정확한 타입은 const char배열이다.
				  // => const char[] => const char* 로 암시적 변환 가능
	
	foo("hello"s); // 2번이 불린다.


	auto s1 = "hello"; // s1 : const char*
	auto s2 = "hello"s; // s2 : std::string
}
