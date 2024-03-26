#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10};

//	auto p1 = s.begin();
//	auto p2 = s.end();

// 	실행해 본후에.. 아래 코드는 변경하지 말고, 거꾸로 출력 되도록
//  위의 코드를 수정해 보세요


//  아래 처럼 하면 된다.
//	auto p1 = std::make_reverse_iterator(s.end());
//	auto p2 = std::make_reverse_iterator(s.begin());

	auto p1 = s.rbegin(); // std::make_reversse_iterator(s.end())와 동일
	auto p2 = s.rend(); // std::make_reverse_iterator(s.begin())과 동일

	while(p1 != p2)
	{
		std::cout << *p1 << ", ";
		++p1;
	}

}
