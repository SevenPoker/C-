#include <vector>
#include <iostream>

// 사용자 정의 메모리 할당기
// => 반드시 템플릿으로 해야하는 것은 아니지만, 
// => 다양한 타입의 메모리 할당이 필요하므로 관례상 템플릿으로

template<typename T>
class debug_alloc
{
public:
	T* allocate( std::size_t sz) 
	{
		void* p = malloc(sizeof(T) * sz);
		printf("allocate : %p %d cnt\n", p, sz);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate : %p %d cnt\n", p, sz);
		free(p);
	}

	// 위 2개 멤버함수외에 아래 3개가 더 필요
	using value_type = T;

	debug_alloc() {} // 디폴트 생성자

	template<typename U>
	debug_alloc( const debug_alloc<U>& ) {} // template 생성자
};



int main()
{
//	std::vector<int> v(5); // std::vector<int, std::allocator<int>> v(5)

	std::vector<int, debug_alloc<int> > v(5);

	v.resize(10);
}
