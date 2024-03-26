#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

void foo(int n){ std::cout << n << ", ";}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    std::for_each(v.begin(), v.end(), foo);

    // C++11 부터 제공되는 람다 표현식 사용
    // 람다 표현식 : 함수 이름(주소)가 필요한 위치에 함수 구현 자체를 적을 수 있는 문법
    //              이름 없는 함수를 만드는 문법
    // [] : lambda introducer
    //      람다 표현식이 시작됨을 알리는 기호
    // void foo 빼고 다적으면 됨. 그리고 앞에 [] 기호 붙이면 된다.

    std::for_each(v.begin(), v.end(),[](int n){ std::cout << n << ", ";});

	return 0;
}
