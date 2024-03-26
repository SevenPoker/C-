#include <iostream>
#include <iterator>
#include <list>
#include <fstream> // c++ 에서 파일 입출력으로 쓰는것


int main()
{
	int n = 10;

	std::cout << n << std::endl;

	//..
	std::ostream_iterator<int> p(std::cout, " ");

	*p = 10; // std::cout << 10 << " "
	*p = 20; // std::cout << 20 << " "

	std::ofstream fout("a.txt");
	std::ostream_iterator<int> p2(fout, " "); // fout에 아래 p2를 써줄게!!

	*p2 = 100;
	*p2 = 1000;

}
