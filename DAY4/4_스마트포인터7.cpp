#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf;
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	// 스마트 포인터를 아래처럼 사용하면 자원 누수가 발생합니다.
	sp1->bf = sp2;
	sp2->bf = sp1;
	// 이렇게 하면 소멸자가 안불린다.

	// kim을 만들고(sp1), lee를 만들고(sp2)
	// 참조계수가 각각 1개이다.
	// 그런데 kim 안의 smartptr이 lee를 가리키고 lee의 smartptr로 kim을 가리킨ㄴ다.
	// 그러면 각각의 참조계수가 각각 1개씩증가되어서 2씩된다.
	// 이 상태에서 빠져나간다 해도 참조계수가 1이 빠지고 1이 남아있기 때문에
	// 소멸자가 안불린다.

	// => 상호 참조, 원형 참조라고 합니다.(cycle reference)
}


