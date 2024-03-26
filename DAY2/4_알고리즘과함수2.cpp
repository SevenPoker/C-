#include <iostream>
#include <list>
#include <algorithm>
#include "show.h"


int foo(int a, int b)
{
    return a + b;
}

int main()
{
    std::list<int> s1 = { 1,2,3,4,5};
    std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s3;

    // transform 알고리즘
    std::transform(s1.begin(), s1.end(), // 1. 이 구간의 내용을
                   s2.begin(),           // 2. 이 구간의 내용과 함께
//                   s3.begin(),           // 4. 함수 결과를 이곳에 넣어라
                   std::back_inserter(s3),
                   foo);                 // 3. 이 함수에 보내서

    // 주석을 보고, foo 가 단항일까 이항일까 생각

    show(s3);


	return 0;
}
