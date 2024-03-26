#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// 선형컨테이너3.cpp
// capacity 개념
int main()
{

	// vector를 통해서 10개의 공간을 만들고
	// 7로 줄이면 안에 size 만 7로 줄인다.
	// capacity는 10 이다.

	std::vector<int> v(10, 0);
	v.resize(7); // 어떻게 구현했을까요 ?

	std::cout << v.size() << ", " << v.capacity() << std::endl;
	
	v.push_back(0); // 끝에 0 추가
					// size < capacity 이므로 메모리 재할당 없음.
					// not expensive!!

	std::cout << v.size() << ", " << v.capacity() << std::endl;

	v.push_back(100);
	v.push_back(1000);
	v.push_back(10);

	std::cout << v.size() << ", " << v.capacity() << std::endl;
	// size == capacity 상태이므로 메모리 재할당 필요
	// expensive 연산!!
	// capacity 를 초과하는 경우에는 처음 10개 할당했을 때 처럼 그 크기만큼 늘어난다.
	// g++ 은 두배만큼 늘린다.
	// 메모리가 부족하면 예외case가 나온다.

	v.shrink_to_fit(); // 필요없는 여분의 메모리 제거
					   // 8개 메모리 재할당해서, 기존 버퍼에서 8개 복사하고
					   // 기존 버퍼는 제거

	std::cout << v.size() << ", " << v.capacity() << std::endl;
}




