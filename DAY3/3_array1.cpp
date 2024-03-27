#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 }; 
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; 

	// 배열과 vector는 메모리 구조가 유사하다.(연속된 메모리를 사용한다.)
	// 사용법도 유사하다.
	x[0] = 10;
	v[0] = 10;

	// 그런데, 차이점은 메모리 위치이다.
	// 배열 : 모든 데이터가 stack
	// vector : 모든 데이터가 Heap

	// 할당 속도는 배열이 벡터보다 빠르다.
	for (int i = 0; i < 10; i++)
	{
		int x1[10]; // 빠르다.
		std::vector<int> v1(10); // 느리다.
	}

	// stack은 할당 해제할떄 성능저하가 없지만 Heap은 중간중간에 빈곳을 찾는거라 할당 해제가 느리다.

}
