#include <iostream>

// Ptr 복사해오세요
// 1. template 으로 만드는 것이 관례 입니다.
// 2. 얕은 복사 문제를 해결해야 합ㄴ다.
//    => 관례적으로 참조계수 기술 사용


template<typename T>
class Ptr
{
	T* obj;
    int *ref; // 참조계수를 넣어서 p2 = p1 일때 2명이 쓰고있다고 알려줘야한다.
public:
	Ptr(T* p = 0) : obj(p)
    {
        ref = new int;
        *ref = 1;
    }

    Ptr(const Ptr& other) : obj(other.obj), ref(other.ref)
    {
        ++(*ref);
    }

	~Ptr() 
    {
        if ( --(*ref) == 0)
        {
            delete obj;
            delete ref;
        }
    }
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
    
};

int main()
{
    Ptr<int> p1 = new int;
    // heap 에 int를 만든다. (100번지라고 하자)
    // p1 객체안에 obj가 100번지를 가리킬꺼다.
    *p1 = 10;

    Ptr<int> p2 = p1; // 이때 현상을 생각해보자.
    // 복사의 경우 
    // p2가 먼저 소멸되고 p1이 그 다음에 소멸된다.
}


