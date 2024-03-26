#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int x[5]= {1,2,3,4,5};

int* first() {return x;}

int main()
{
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };

    // 2번째 부터 검색하려고 한다.
    auto p = std::find( ++s.begin(), s.end(), 3);
    auto p = std::find( std::next(s.begin()), s.end(), 3);

    auto p3 = ++first(); // error
    auto p4 = std::next(first()); // ok.
}
