#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	std::list<int> s2 = { 1,2,3 };

    auto p = s2.begin();
    auto p2 = s2.cbegin(); // const iterator. 쓰기가 안됨

    *p1 = 10; // ok           mutable iterator
    *p2 = 20; // error.       immutable iterator

    // 양방향 반복자 : 읽기, ++, -- 가 가능한 반복자
    //                쓰기는 요구조건이 아닙니다.
    //                될 수도 있고 안될수도 있다.    
}
