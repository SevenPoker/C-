#include <iostream>
#include <mutex>

// 단위전략 (policy base design)
// => 클래스가 사용하는 다양한 정책을 교체할수 있게 하기 위해서
// => 템플릿 인자로 정책을 담은 클래스를 전달하는 디자인 기법
// => 성능저하없이 교체 가능.
// => C++ 진영에서 아주 널리 사용하는 기술
// => STL의 컨테이너가 대부분 이 디자인을 사용

// 주의!! ) STL의 List는 동기화를 고려해서 디자인 되지는 않았다.
// => 다른 용도로 이 기술을 사용


template<typename T, typename ThreadModel = NoLock> class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		// ......
		tm.unlock();
	}
};
// 동기화 정책 클래스
// => 규칙은 반드시 lock/unlock 이 있어야 한다.
class NoLock
{
public:
	inline void lock() {}
	inline void unlock() {}
};

class MutexLock
{
	std::mutex m;
public:
	inline void lock() {m.lock(); std::cout << "lock\n";}
	inline void unlock() {m.unlock(); std::cout << "unlock\n";}
};


List<int, Nolock> st;
// List<int, MutexLock> st;
// List<int> st; // default 정책인 NoLock 사용

int main()
{
	// 하지만 객체에 무조건 lock, unlock넣으면 성능저하가 됨.
	// 따라서 선택을 하게 해줘야한다.
	st.push_front(10);
}
