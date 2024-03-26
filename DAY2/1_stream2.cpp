#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

int main()
{
	std::list<int> s = { 1, 2, 3, 4, 5 };

	std::ostream_iterator<int> p1(std::cout, " ");

	// list의 모든 요소를 화면 출력하는 코드
	std::copy(std::begin(s), std::end(s), p1);


	std::ofstream fout("b.txt");
	std::ostream_iterator<int> p2(fout, " ");
	std::copy(std::begin(s), std::end(s), p2);


}
