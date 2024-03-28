#include <iostream>
#include <chrono>

int main()
{
	// 길이를 나타내는 단위를 설계해 보자.
	using Meter = std::chrono::duration<int, std::ratio<1,1>>;
	using KiloMeter = std::chrono::duration<int, std::ratio<1000,1>>;
	using CentiMeter = std::chrono::duration<int, std::ratio<1,100>>;

	KiloMeter km(1); // 1km

	CentiMeter cm(km);

	std::cout<< cm.count() <<std::endl;

}
