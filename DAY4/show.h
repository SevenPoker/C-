//show.h
#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <functional>

// chronometry() & stop_watch
class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};


template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	stop_watch sw(true);
	return std::invoke(std::forward<F>(f), std::forward<Types>(args)...);
}


template<typename C>
void show(const C& c)
{
	for( auto& e : c)
		std::cout << e << ", ";

	std::cout << std::endl;
}

// 반복자 버전
template<typename InputIter>
void show(InputIter first, InputIter last)
{
	std::ostream_iterator< 
			typename std::iterator_traits<InputIter>::value_type > p(std::cout, ", ");

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

	using value_type = T;
	debug_alloc() {} 

	template<typename U>
	debug_alloc( const debug_alloc<U>& ) {} 
};

template<typename T>
bool operator==(const debug_alloc<T>& a1, const debug_alloc<T>& a2)
{
	return true;
}
template<typename T>
bool operator!=(const debug_alloc<T>& a1, const debug_alloc<T>& a2)
{
	return false;
}