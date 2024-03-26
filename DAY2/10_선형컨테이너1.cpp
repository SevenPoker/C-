// 6_선형컨테이너
// C++98 에서 3개
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
	std::list<int> c = { 1,2,3 };

	c.push_back(5);
	c.push_front(5); // vector 라면 에러.

}
