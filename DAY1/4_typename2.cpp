#include <iostream>
#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& v)
{
	int n = v.front();
	std::cout << n << std::endl;
}
*/

/*
template<typename T>
void print_first_element(std::vector<T>& v)
{
	T n = v.front();

	std::cout << n << std::endl;
}
*/

template<typename T>
void print_first_element(T& v)
{
	// 아래 auto 말고 다른방식으로 쓸려면??
	// T는 std::list<double> 형이기 때문에 T로 사용할수는 없다.

	// 따라서 컨테이너 T가 저장하는 요소의 타입을 알고 싶을때는 아래처럼 하면된다.
	typename T::value_type n = v.front();

	// 이 예제는 auto를 쓰면 되긴합니다.
	std::cout << n << std::endl;
}


int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<double> v = {1,2,3,4,5,6,7,8,9,10};
	std::list<double> v = {1,2,3,4,5,6,7,8,9,10};
	print_first_element(v);
}

// 모든 template 기반의 컨테이너는 "자신이 저장하는 요소의 타입"이 있다.
// 그 타입을 외부에서 알고싶을떄가 이는데
// 위에 만든 print_fisrt_element 처럼
// 그래서 STL이 아래처럼 설계 되었다.
template<typename T>
class list
{
public:
	using value_type = T;
}


// 클래스				: 멤버 데이터 + 멤버함수로 구성
// 클래스 템플릿 (STL)	: 멤버 데이터 + 멤버 함수 + 멤버 타입 으로 구성 (value_type) 같은 개념


// cppreference.com 에서 std::list 검색