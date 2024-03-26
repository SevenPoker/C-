#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

int main()
{
    std::ifstream fin("1_stream4.cpp");

    std::istream_iterator<char> p1(fin);
    std::istream_iterator<char> p2;

//    std::cout << *p1 << std::endl;
//    ++p1;
//    std::cout << *p1 << std::endl;

}
