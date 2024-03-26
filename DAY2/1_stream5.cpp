#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

int main()
{
    std::ifstream fin("1_stream5.cpp");

//  아래 반복자는 white space(공백, tab, backspace 등) 입력이 안된다.
//    std::istream_iterator<char> p1(fin);
//    std::istream_iterator<char> p2; // 인자를 안주면 파일의 끝(EOF)


// 그냥 일반적으로 cin으로 할 수 있지만 copy 기능을 써서 편리하게 할려고 이렇게
// 반복자로 한거다.
    std::istreambuf_iterator<char> p1(fin);
    std::istreambuf_iterator<char> p2; // 인자를 안주면 파일의 끝(EOF)

    std::ostream_iterator<char> p3(std::cout, "");

    std::copy(p1,p2,p3);

}
