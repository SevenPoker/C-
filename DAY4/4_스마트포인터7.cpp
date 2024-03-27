#include "helper.h"
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

}


