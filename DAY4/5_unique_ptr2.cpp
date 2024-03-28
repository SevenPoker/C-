#include <memory>
#include <iostream>

// std::shared_ptr : 자원을 공유할 수 있는 스마트 포인터
// std::weak_ptr   : 소유권이 없는 스마트 포인터
// std::unique_ptr : 자원을 독점하는 스마트 포인터

int main()
{
	std::unique_ptr<int> up1(new int); // ok
//	std::unique_ptr<int> up2 = up1; // error
	// 다른 smart pointer와 공유하는 것은 오류!!

	std::unique_ptr<int> up3 = std::move(up1); // ok

	std::unique_ptr<int> up4 = std::make_unique<int>();

	std::cout << sizeof(up1) << std::endl;
	// overhead 가 없다.
}
