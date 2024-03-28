#include <vector>
#include <string>

void f1(std::vector<int> v) {}
void f2(std::string s) {}

int main()
{
	// 안이상하다
	f2("hello"); // ok
	std::string s1 = "hello"; // ok
	std::string s2("hello"); // ok
							// 그래서 string(const char*) 생성자는 explicit 아님.


	f1(10); // error (모양이 이상핟.)
	std::vector<int> v1=10; // error 
	std::vector<int> v2(10); // ok
						// vector(int) 생성자는 explicit!!
}
