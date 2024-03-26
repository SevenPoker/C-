#include <vector>

// 기본적으로는 std의 기본 allocator를 쓴다.
// new와 delete로 이루어져 있다.
template<typename T, typename Ax = std::allocator<T>> 
class vector
{
	Ax ax; // 메모리 할당기 (allocator)
		   // vector의 모든 멤버 함수에서 메모리 할당이 필요하면
		   // ax 객체의 멤버함수를 사용해야 한다.
public:
	void resize(int sz)
	{
		T* p = ax.allocate(sz); // 할당

		ax.deallocate(p, sz);   // 해지
	}
};

int main()
{
	std::vector<int> v(5);
	v.resize(10);
}


