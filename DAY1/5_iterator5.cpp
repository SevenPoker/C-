#include <iostream>
#include <list>

int main()
{
	std::list<int> s1 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s1.end(); // 핵심 : 마지막 요소가 아닌 마지막 다음을 가리키는 반복자
						// past the last element
	*p1 = 10; // ok
	*p2 = 10; // runtime error, bug

	// [p1, p2)
	// .end() 로 꺼낸 반복자는 비교의 용도로만 사용해야한다.

	while (p1 != p2)
	{
		++p1;
	}


	// 아래 3개는 모두 empty 조사한것
	std::list<int> s3;
	if (s3.empty()) {}

	if (std::begin(s3) == std::end(s3)) {}	
	if (s3.begin() == s3.end()) {}	
}
