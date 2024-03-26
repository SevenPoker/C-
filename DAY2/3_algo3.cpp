#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
//	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
    std::list<int> v = { 1,2,3,1,2,3,1,2,3,1 };

//  list의 경우 앞으로 당기는 경우 성능이 저하되기 때문에
//  멤버함수로 remove를 제공한다.

/*
	auto p = std::remove(v.begin(), v.end(), 3);
	show(v);  
	v.erase(p,v.end());
*/
    // list 도 위 코드는 에러가 없이 잘 동작하지만 성능이 안좋다.
    // 그래서 list 는 멤버 함수 remove가 있다.

    v.remove(3);
	show(v);

	return 0;
}

// 핵심 : 알고리즘과 동일한 이름의 멤버 함수가 있다면
// => 멤버 함수를 사용해라!!

// 왜 알고리즘과 동일한 이름의 멤버함수를 제공하는가??

// 1. 컨테이너 반복자를 알고리즘에 보낼 수 없을때
//    std::sort(list_iterator); // error
//    list.sort(); // ok

// 2. 컨테이너 반복자를 알고리즘에 보낼 수 있지만 보다 최적화된 구현이 있을때
//    std::remove(list_iterator) // ok 에러가 아님
//    list.remove(3) // 위 코드보다는 여기가 더 성능이 좋음
