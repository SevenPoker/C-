#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<int> up(new int); // 독점
	std::shared_ptr<int> sp(new int); // 허용

	// 다음중 에러는 ?
	std::shared_ptr<int> sp1 = up; // error
	std::shared_ptr<int> sp2 = std::move(up); // ok

	std::unique_ptr<int> up1 = sp; // error
	std::unique_ptr<int> up2 = std::move(sp); // error
}

// shared_ptr : 자원의 공유 허용
// unique_ptr : 자원의 공유 허용 안함 독점
