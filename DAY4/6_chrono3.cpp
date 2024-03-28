#include <iostream>
#include <chrono>
using namespace std::literals;

int main()
{
	// 1. predefined typedef
	std::chrono::hours		 h(1);     // typedef duration<int, ratio<3600,1>> hours;
	std::chrono::minutes      m  = h; // using minutes = duration <int, ratio<60,1>>
	std::chrono::seconds      s  = h; // using seconds = duration <int, ratio<1, 1>>
	std::chrono::milliseconds ms = h; // using milliseconds = duration <int, ratio<1, 1000>>
	std::chrono::microseconds us = h;
	std::chrono::nanoseconds  ns = h;

	std::cout << h.count() << std::endl;
	std::cout << m.count() << std::endl;
	std::cout << s.count() << std::endl;
	std::cout << ms.count() << std::endl;
	std::cout << us.count() << std::endl;
	std::cout << ns.count() << std::endl;

	// 2. literals( h, min, s, ms, us, ns )
	std::chrono::seconds sec = 1min;

	sec = 1min + 3s;
	sec += 40s;
	std::cout << sec.count() << std::endl;

	std::chrono::seconds sec2 = 1min + 3s;
	std::cout << sec2.count() << std::endl;
}
