#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

// 단항함수 (unary function) : 인자가 한개인 함수
// 이항함수 (binary function): 안저거 2개인 함수

// for_each 의 3번째 인자는 단항 함수 이어야 합니다.

void foo(int n)
{
    std::cout << n << ", ";
}



int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // STL은 많은 알고리즘이 인자로 함수를 받고 있다.    
    // for_each 알고리즘
    std::for_each(v.begin(), v.end(), foo);


	return 0;
}

