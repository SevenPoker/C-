#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 헥심 : 알고리즘은 컨테이너를 알지 못한다.

// std::remove : 조건을 만족하는 요소를 찾으면 실제 메모리 제거가 아닌
// 뒤의 요소를 앞으로 이동해 놓게 되고
// 또한, 컨테이너 자체의 크기도 줄이지 않는다.
// 반환 값으로 유효하지 않은 구간의 시작을 나타내는 반복자 반환

// 알고리즘은 "컨테이너를 알 수 없기 떄문에" 메모리를 줄일수느느 없다.
// 크기나, 메모리를 제거하려면 "멤버함수로" 해야한다.


int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = std::remove(v.begin(), v.end(), 3);

	show(v);  

// 해보면 끝에 3이 그대로 있다.
// 일반 remove함수에서는 container를 모른다.
// 그래서 3을 찾으면 뒤의 데이터를 앞으로 당기고
// 나머지 뒤에 3개 남은것들은 그냥 쓰레기 값으로 남아있다.
// 원본        {1,2,3,1,2,3,1,2,3,1};

	v.erase(p,v.end());

	show(v);

	return 0;
}






