#include <string> 
#include <algorithm>
#include <functional>
#include <iostream>

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XY";

	auto ret1 = std::max(s1,s2); // "XY"
	// s1, s2 를 < 연산으로 비교한다.


	// s1, s2 중 문자열의 길이가 큰 것은?
	auto ret2 = std::max(s1.size(), s2.size()); 
	// 이렇게 해도 되지만, 이 코드는 반환타입도 int 이다.

	auto ret3 = std::ranges::max(s1, s2, std::less{}, &std::string::size);
	// s1, s2의 멤버중 4번째 인자로 보낸 멤버를 호출한 결과를
	// 3번째 인자로 보낸 함수(객체)로 비교해달라.
	// 4번쨰 인자를 projectiond 이라고 부른다.
	// s1,s2 =====> projection을 통과한 결과를 ====> 비교함수로 전달.

	auto ret4 = std::ranges::max(s1, s2, {}, &std::string::size);
	// 이렇게 표현할수도 있다.
}