#include <iostream>
#include <list>
#include <algorithm>


// reverse iterator 원리
template<typename ITER> class Reverse_iterator
{
    ITER iter; 
public:
    Reverse_iterator(ITER i) { iter = i; --iter; }

    Reverse_iterator& operator++()
    {
        --iter;
        return *this;
    }

    typename ITER::value_type operator*()
    {
        return *iter;
    }

    // ==, !=, --(++)
};


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	auto p1 = std::end(s);

	std::Reverse_iterator< list<int>::iterator> p2( p1 );

    ++p2;
    ++p2;

    std::cout << *p2 << std::endl;

}











//
