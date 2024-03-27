// 선형컨테이너 (sequence container)
// C++98 에서 3개
// #1. 메모리 구조 알아 두세요.
// #2. 반복자의 종류
#include <vector>  // 연속된 메모리, 임의접근 반복자
#include <deque>   // 연속된 메모리와 유사, 임의접근 반복자
#include <list>    // 떨어진 메모리, 양방향 반복자

// C++11 추가된 2개
#include <forward_list> // 전진형 반복자
#include <array>		// 임의접근 반복자

#include "show.h"

int main()
{
	// 선형 컨테이너 는 사용법의 거의 동일 합니다.
	std::list<int> s = { 1,2,3 };
	std::vector<int> v = { 1,2,3 };
	std::deque<int> d = { 1,2,3 };

	s.push_back(5);
	v.push_back(5);
	d.push_back(5);

	// 사용법이 다르면 의도적인 설계이다.
	s.push_front(0); // ok
	d.push_front(0); // ok
	v.push_front(5); // vector 에러.

	// [] 은 list가 안된다.
	s[0] = 0; // error
	d[0] = 0; // ok
	v[0] = 0; // ok

	// [] 가 필요하고, 전방삽입이 필요없다 : vector
	// [] 가 필요하고, 전방삽입이 필요하다 : deque
	// 삽입 삭제가 많다 : list

	// but 일반적으로는 vector 권장
	// cpu 안에 캐쉬 메모리가 있기 때문에 연속된 메모리를 올릴 가능성이 훨씬 높다
	// 따라서 vector가 대부분 유리하다.
}
