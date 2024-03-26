#include <iostream>
#include <list>   
#include <vector>
#include <ranges>



int main()
{
//	std::list<int> s = { 1,2,3,4,5 };
//	std::vector<int> s = { 1,2,3,4,5 };
	int s[] = { 1,2,3,4,5 };
	
	// 반복자를 꺼내는 법
	// #1. C++98 스타일
	// => 아래처럼 사용하면 container 변경이 필요하다.
	//std::list<int>::iterator p = s.begin();

	// #2. 그래서 auto를 권장합니다.
	//auto p = s.begin(); // s가 배열인 경우는 error

	// #3. 멤버가 아닌 일반함수 std::begin() 이 좀 더 유연성이 있다.
	auto p = std::begin(s); // s가 배열이라도 ok.

	// #4. C++20 부터 새로운 begin 등장
	auto p2 = std::ranges::begin(s); // 가장 안전한 코드
	auto p1 = std::begin( std::list{1,2,3}); // ok 하지만 임시객체 때문에 나가고 나면 바로 파괴!!
	//auto p1 = std::ranges::begin(std::list{1,2,3}); // error
}



