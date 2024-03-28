#include <iostream>
#include <string>
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//std::shared_ptr<People> bf;
    // 진짜 포인터로 도입하자
    People* bf;
    // raw pointer는 shared_ptr의 참조계수에는 아무런 영향을 주지 않는다.
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	sp1->bf = sp2.get();
	sp2->bf = sp1.get();
    // 이코드는 자원은 안전하게 파괴됩니다.
    // 그런데 문제가 발생한다!! 9번에서 확인

}
