#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

template<typename C>
void show(const C& c)
{
    for ( auto& e : c)
        std::cout << e << ", ";

    std::cout << std::endl;
}

template<typename InputIter>
void show(InputIter first, InputIter last)
{
    // 진짜 포인터 (ex, int*, char*)가 있을 수 있기 때문에 iterator_traits를 통해서
    // 한번 계층을 거쳐서 꺼내줘야한다.
    std::ostream_iterator<typename std::iterator_traits<InputIter>::value_type> p(std::cout,", ");
    std::copy(first, last, p);
    std::cout << std::endl;
}

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
