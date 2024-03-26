#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

int main()
{
    std::ostream_iterator<int> p1(std::cout, " ");
    std::istream_iterator<int> p2(std::cin);

    int n = *p2; // std::cin >> n;

    *p1 = n; // std::cout << n << " ";

}
