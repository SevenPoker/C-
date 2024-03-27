#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

class default_sentinel_t {};

default_sentinel_t default_sentinel;

template<typename ITER>
class mycounted_iterator 
{
	ITER iter;
	std::size_t cnt;
public:
	mycounted_iterator(ITER i, std::size_t c) : iter(i), cnt(c) {}

	mycounted_iterator& operator++() { ++iter; --cnt; return *this;}
	typename ITER::value_type & operator*() { return *iter;}

	std::size_t count() const { return cnt; }

	bool operator==(const default_sentinel_t& s) const
	{
		return cnt == 0;
	}
};
int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	mycounted_iterator ci(v.begin(), 5);

	while( ci != default_sentinel )
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}