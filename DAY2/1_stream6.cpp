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

int main()
{
    std::list<int> s = {1,2,3,4,5,6,7,8,9,10};
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    // s의 모든 내용 출력

    show(x);
    show(s);

    // 반복자 버전
    show(s.begin(), s.end());
    show(x, x+10);
}
