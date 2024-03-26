#include <iostream>
#include <list>
#include <filesystem>

// 반복자의 종류
// 1. 컨테이너에서 꺼내는 것 (s.begin())
// 2. 독립적으로 만들어서 사용하는 반복자도 있다.
// 3. raw pointer 도 반복자의 일종입니다.


// 반복자 정의 : * 로 요소 접근 가능하고, ++로 이동 가능한 모든 것


int main()
{
	std::filesystem::directory_iterator p("C:\\windows");

	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}










