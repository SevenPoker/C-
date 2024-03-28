#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

//    People* bf;

	std::weak_ptr<People> bf; // 소유권이 없는 스마트 포인터
	// 참조계수가 증가하지 않고
	// 객체 파괴여부를 조사할수 있다.

};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
    {
        std::shared_ptr<People> sp2(new People("lee"));

        sp2->bf = sp1;
        sp1->bf = sp2;
    }

    if (sp1->bf.expired())
    {
        std::cout << " destroyed\n";
    }
	else
	{
		// 파괴되지 않은 경우 객체에 접근하려면
		// auto name = sp1->bf->name; // 이렇게 접근이 불가능하다 weak로는 접근 불가능

		// smart ptr이 접근할 수 있는 권한이 있지만 weakptr은 권한이 없다
		// 예를들어 쓰레드로 smart ptr이 돌고있다가 소멸되면 그 와중에 weak ptr이 점유하고 있으면
		// 메모리 참조가 파괴되기 때문에 안됨
		// 따라서 다른 smart ptr을 만들어서 권한을 얻은 다음에 접근을 해야한다.(객체 파괴 안됨)
		
		// weakptr로 접근할려고 할때 다른 스레드에서 파괴 될수 있으니까
		// 일단 mutex lock 건다.
		std::shared_ptr<People> sp = sp1->bf.lock();

		// 근데 만들때 파괴가 될 수있으니까 sp를 한번 더 확인해줘야한다.
		// sp 를 다시 확인 후 사용해야 한다.
		if (sp)
		{
			// sp 사용....
			auto name = sp->name;
		}
	}
}


// 관리객체의 파괴는 맨 마지막에 일어나야한다.
// 먼저 파괴가 되면 weak가 가리키고 있는 중인데 관리객체가 파괴되었는지 아닌지를 모른다.
// weak가 먼저 파괴된 다음에 관리 객체가 파괴되어야함
// make_shared_ptr으로 하면 (객체 + 관리객체) 한번에 할당이 되기때문에
// 소멸자는 불리지만 관리객체 해지는 안한다.
