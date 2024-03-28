#include <iostream>
#include <chrono>

using Meter = std::chrono::duration<int>;
using KiloMeter = std::chrono::duration<int, std::kilo>;
using CentiMeter = std::chrono::duration<int, std::centi>;

// unsigned long long
KiloMeter operator ""_km(unsigned long long n)
{
	KiloMeter k(static_cast<int>(n));
	return k;
}

Meter operator ""_m(unsigned long long n)
{
	Meter m(static_cast<int>(n));
	return m;
}

int main()
{
	auto k1 = 2_km; // operator""_km(2)
	auto k2 = 3_km;

	Meter m = k1 + 30_m + k2;

	std::cout << m.count() << std::endl;

}
