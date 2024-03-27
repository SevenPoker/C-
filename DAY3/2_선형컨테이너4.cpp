#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"

// 컨테이너를 보관하는 컨테이너

int main()
{
	std::vector<int> v1(10, 0);
	v1[0] = 10;

	// 컨테이너를 보관하는 컨테이너
	std::vector<std::vector<int>> v2(10);
	// v2 의 사이즈는 10개이지만 그 각각의 vector의 사이즈(v[0],v[1]...)는 0이다.

	// 각각 vector의 사이즈를 정하고 싶으면?
	std::vector<std::vector<int>> v2(10,{10}); // 이렇게 하면 v2[0]의 size는 1이다.
	
	std::vector<std::vector<int>> v2(10,std::vector<int>(10)); // ok

	std::cout << v2[0].size() << std::endl; // 
	v2[0][0] = 10;


	std::vector<std::list<int>> v3(10);

	v3[0].push_back(1);
	v3[0].push_back(2);


}
