#include <iostream>
#include <string>
#include "show.h"

// STL string 은 "SSO" 알고리즘 사용
// => Small String Optimization
// string 만들어서 문자열을 만들면 heap에 올려서
// 포인터로 가리키는데
// 문자열이 작으면 포인터로 굳이 가리켜야되나?? 그래서
// 포인터 자리에 스트링을 저장한다.

// 지금은 다 그렇게 되어있다.



// 16자 이하 : string 객체 내부에 문자열 보관
// 16자 이상 : heap을 할당해서 문자열 보관
using dstring = std::basic_string<char, std::char_traits<char>, debug_alloc<char>>;

int main()
{
	for(int i = 0; i < 20; i++)
	{
		std::cout << i << std::endl;
		dstring s(i, 'A');
	}
}
