#include <iostream>
#include <vector>
#include <thread>

template<typename T> 
void foo(T a) {}

int main()
{
	// foo 를 호출
	foo(3);		
	// 인자 3을 통해서 T의 타입 추론이 가능하다.

	// #1. foo 를 스레드로 실행해 보세요
//	std::thread t1(&foo, 3); // error. foo 의 타입 T를 추론할 수없다.

	std::thread t(&foo<int>, 3); // ok
	t.join();

	// #2. thread 객체의 copy 와 move
	std::thread t1(&foo<int>, 3); 
//	std::thread t2 = t1; // error. std::thread는 복사생성자가 delete

	std::thread t3 = std::move(t1); // ok, t1이 모든걸 t3에 넘겼기 때문에 가능
	// t3가 주도권을 잡음

	t3.join();

	// #3. thread 객체를 먼저 만들고 나중에 스레드 생성
	std::thread t4;

	t4 = std::thread(&foo<int>, 3); // 우변이 임시객체. 임시객체는 자동으로 move 된다.

	// #4. 여러개의 스레드를 vector로 관리하는 기술
	std::vector<std::thread> v(10);  // 10개를 미리 생성하고

	v[0] = std::thread(&foo<int>, 3);
	v[1] = std::thread(&foo<int>, 3);

	t4.join();
	v[0].join();
	v[1].join();

}
