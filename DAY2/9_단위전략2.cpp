#include <vector>

// resize 의 원리를 생각해 봅시다.
template<typename T> 
class vector
{
public:
	void resize(int sz)
	{
		// 메모리 할당이 필요한 경우 어떻게 할까요 ?
		// new ? malloc ? memory pool
	}
};

int main()
{
	std::vector<int> v(5);
	v.resize(10);
}


