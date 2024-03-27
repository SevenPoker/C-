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

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	std::counted_iterator ci(v.begin(), 5);

	// ? 채워 보세요.
	auto ret = std::find(ci, ?, 3);
}

