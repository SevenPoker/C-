#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

template<typename C>
void show(const C& c)
{
    for ( auto& e : c)
        std::cout << e << ", ";

    std::cout << std::endl;
}

template<typename InputIter>
void show(InputIter first, InputIter last)
{
    // 진짜 포인터 (ex, int*, char*)가 있을 수 있기 때문에 iterator_traits를 통해서
    // 한번 계층을 거쳐서 꺼내줘야한다.
    std::ostream_iterator<typename std::iterator_traits<InputIter>::value_type> p(std::cout,", ");
    std::copy(first, last, p);
    std::cout << std::endl;
}
