#include <iostream>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

// 개념 : 임의의 객체가 다른 타입의 포인터 역할을 하는것
// 원리 : -> 와 * 연산자를 재정의 해서 포인터처럼 보이게 하는것
// 장점 : 진짜 포인터가 아닌객체
//		  생성/복사/대입/파괴의 순간에 추가적인 작업 가능
//        대표적 활용이 소멸자에서 자원을 delete 하는 기능

// 아래 코드가 핵심
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj;}
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};


int main()
{

// p는 객체인데 Car의 pointer처럼 보인다.
	Ptr p = new Car; // Ptr p(new Car)

	p->Go();  // "Ptr의 객체 p"가 "Car*" 처럼 사용된다.
			  // 연산자 재정의
			  // (p.operator->()) Go() 의 모양인데.
			  // (p.operator->())->Go() 의 형태로 해석된다. // 이거는 문법이다.

	// 진짜 pointer 처럼 사용하기 위해서는 아래도 되어야한다.
	(*p).Go(); 

	// p 는 main문 벗어났을때 소멸자가 호출이 된다.
	// 따라서 소멸자에 메모리 해제 기능을 넣어주면 완벽하다.



}


