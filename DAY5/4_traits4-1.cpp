#include <iostream>
#include <type_traits>
#include <vector>

void foo(T& c)
{
	auto n = c.front();

	// auto 는 반드시 우변이 있어야한다.
	// c의 요소와 같은 타입의 변수를 보관하는 컨테이너가 필요하면
	std::vector<typename T::value_type > v2; // ok

	// 그런데, value_type이 없는 컨테이너라면?? (사용자 컨테이너 라면??)
	// decltype() 을 사용하면 타입 조사 가능.
	
///	decltype(c.front()) n2; // 컴파일러가 안다. 선언부를 알기떄문에.
	// 근데 error, c.front()의 결과는 value가 아닌 value& 이기 떄문에

	typename std::remove_reference<decltype( c.front() )>::type n2;

	std::vector< typename std::remove_reference<decltype( c.front() )>::type > v3;

}

int main()
{
	std::vector<int> v = {1,2,3};
	foo(v);
}

