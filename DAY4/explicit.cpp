#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<int> up(new int);
	std::shared_ptr<int> sp(new int);

	// 다음중 에러는 ?
	std::shared_ptr<int> sp1 = up;
	std::shared_ptr<int> sp2 = std::move(up);

	std::unique_ptr<int> up1 = sp;
	std::unique_ptr<int> up2 = std::move(sp); 
}

int* Alloc()
{
	return new int;
}

int main()
{
	Alloc();
}
