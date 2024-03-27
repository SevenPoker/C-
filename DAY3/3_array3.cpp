#include "show.h"
#include <array> // C++11 에서 추가된 std::array

int main()
{
	std::array<int, 5> arr = {1,2,3,4,5};

	std::cout << arr.size() << std::endl;

	// std::array 는 결국 "raw array" 이다.
	// "raw array 로 할 수 없는 작업"은 std::array로도 불가능합니다.
	arr.push_back(0); // error 진짜 배열이 들어있기 때문에 사이즈를 키울수 있는 방법은 없다.
	arr.resize(20); // 이것도 마찬가지로 안된다.

}
