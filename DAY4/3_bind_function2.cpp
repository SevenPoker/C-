#include <iostream>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수

    // std::bind -> 기존 함수(객체)의 특정 인자를 고정한 새로운 함수 만드는 도구
    //              M항 함수 => N 항 함수로 만들기 (단, M >= N)
    
    // 사용법 : std::bind(&M항 함수, M개 인자)

    auto f1 = std::bind(&foo, 1, 2, _1, _2); // 4항 함수 => 2항 함수로 변경

    f1(10,3); // foo(1,2,10,3);

    // 아래 코드는 4항 함수의 1개 인자를 고정해서 3항 함수를 만드는 코드
    // _1, _2 는 std::placeholders에 들어있다.(class의 객체)

    // foo 인자 4개를 받는데 받을때 순서를 각자의 위치(_2,_3,6,_1)에 넣는다.
    auto f2 = std::bind(&foo, _2, _3, 6, _1);
    f2(9,4,8); // foo (4,8,6,9) 나오도록 위를 만들어보자

    auto f3 = std::bind(&foo, std::placeholders::_2, _3, 6, _1);

    //-----------------------------------
    // std::bind() 의 반환 타입은 "함수 객체"인데.
    // bind() 인자에 따라 모두 다른 타입 입니다.

    std::cout << typeid(f1).name() << std::endl;
    std::cout << typeid(f2).name() << std::endl;

    // bind()의 반환 타입이 다르기 때문에
    // "container" 에 보관할 수 없습니다.
    // => 해결책이 std::function
    
}

