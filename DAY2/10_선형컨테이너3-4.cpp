#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1(10);
	v1.resize(4);

	// 핵심 : vector의 복사 생성자에 대해서!!
	std::vector<int> v2 = v1;
	std::vector<int> v3;
	std::copy(std::begin(v1),std::end(v1),std::back_inserter(v3));

	std::cout << v2.size() << ", " << v2.capacity() << std::endl;
	std::cout << v3.size() << ", " << v3.capacity() << std::endl;

	// g++은 c++98 시절에는 shrink_to_fit() 이 없었다. C++11 부터 제공
	// 그래서 예전에는 아래처럼 했다.

	std::vector<int> v4(10);
	v4.resize(4);

	// shrink_to_fit() 없이 여분의 메모리 제거
	std::vector<int>(v4).swap(v4);
    //  --------------// 여기까지가 임시객체 (아래 코드로 갈때 지워진다.)
	// swap 인 경우는 각자의 버퍼내용을 바꾼다.

	std::cout << v4.capacity(); // 4

}

