#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
public:
};

void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", &goo);

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




