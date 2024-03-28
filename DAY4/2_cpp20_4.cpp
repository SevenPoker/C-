#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

// C++98 의 find
template<typename T1, typename T2>
T1 myfind(T1 first, T1 last, const T2& c)
{
	while ( first != last && *first != c)
		++first;

	return first; 
}


template<typename T1, typename S, typename T2>
T1 cpp20find(T1 first, S last, const T2& c)
{
	while ( first != last && *first != c)
		++first;

	return first; 
}



int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	std::counted_iterator ci(v.begin(), 5);

	// ? 채워 보세요.
	// 아래처럼 하면 되지않을까!??
	// ㄴㄴ 안된다 ci와 sentinel이 같은 type이어야 한다.
	// 그래서 위의 cpp20find와 같이 만들었다.
//	auto ret = std::find(ci, std::default_sentinel, 3);

	// 기존code도 동일하게 동작을 해야하기 때문에
	// 아래 range에 넣어놨다.
	auto ret = std::ranges::find(ci, std::default_sentinel, 3);
}

