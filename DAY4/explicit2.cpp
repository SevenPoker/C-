#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s) {}

int main()
{
	f2("hello");
	std::string s1 = "hello";
	std::string s2("hello");

	f1(10);
	std::vector<int> v1=10;
	std::vector<int> v2(10);
}