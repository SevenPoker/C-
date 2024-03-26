#include <iostream>
#include <list>   
#include <vector>

// 반복자 무효화
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	auto p = v.begin();

	std::cout << *p << std::endl;

	v.resize(10); 
	// 이 순간에 v가 사용하는 내부 버퍼가 변경되기 때문에 이전에 꺼낸 모든 반복자는 사용하면 안됩니다.
	// Iterator invalidate 라고 합니다.

	v.resize(3);
	// 작아지게 되면 버퍼 변경 안된다. 그대로 남아있다.

	std::cout << *p << std::endl;

}



