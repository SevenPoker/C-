#include "show.h"
#include <array> // C++11 에서 추가된 std::array

int main()
{
	std::array<int, 5> arr = {1,2,3,4,5};

	std::cout << arr.size() << std::endl;

	arr.push_back(0);
	arr.resize(20);

}