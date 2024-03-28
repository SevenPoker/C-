#include <iostream>
#include <chrono>

int main()
{
	// 길이를 나타내는 단위를 설계해 봅시다.
//	using Meter      = std::chrono::duration<int, std::ratio<1,1>>;
//	using KiloMeter  = std::chrono::duration<int, std::ratio<1000, 1> >;
//	using CentiMeter = std::chrono::duration<int, std::ratio<1, 100> >;

    using Meter      = std::chrono::duration<int>;
	using KiloMeter  = std::chrono::duration<int, std::kilo >;
	using CentiMeter = std::chrono::duration<int, std::centi >;

	KiloMeter km(1); // 1km
	CentiMeter cm(km);
	std::cout << cm.count() << std::endl;
    
	CentiMeter cm2(123);
//	Meter m = cm2; // error. 작은 타입의 값을 큰 타입에 넣으면 데이타 손실

    Meter m = std::chrono::duration_cast<Meter>(cm2);

    std::cout << cm2.count() << std::endl; // 1

}
