#include <iostream>
#include <unordered_set>
#include "show.h"

// hash 함수

// collision 이 많으면 hash 가 느리다.
// 데이터량이 적고 검색이 빨라야하는거면 hash를 쓰자
// 데이터량이 많으면 쓰지말라

int main()
{
    // C++ 표준 해쉬 함수는 함수 객체(template )이다.
    std::hash<int> hi;
    std::hash<double> hd;
    std::hash<std::string> hs;

    std::cout << hi(100) << "..." << hi(100) % 13 << std::endl;
    std::cout << hd(3.4) << "..." << hd(3.4) % 13 <<  std::endl;
    std::cout << hs("ABC") << "..." << hs("ABC") % 13 <<  std::endl;
    std::cout << hs("XYZ") << "..." << hs("XYZ") % 13 <<  std::endl; // 이거랑 
    std::cout << hs("aaa") << "..." << hs("aaa") % 13 <<  std::endl; // 이거랑 충돌난다. 기본 std::hash는 13의 버킷사이즈

}

