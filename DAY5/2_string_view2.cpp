#include <iostream>
#include <string>
#include <string_view>

// void bad(std::string s) { } // call by value : 복사본의 오버헤드가 있다.

void good(const std::string& s) {}
// s 는 포인터다. string 포인터가 하나 만들어지고 s의 객체에 접근해서 거기에 있는 포인터를 타고
// 문자열로 들어간다.

void best(std::string_view   s) {}
// 바로 접근을 한다.

int main()
{
	std::string s = "to be or not to be";

//	good(s);
//	best(s);

	// 아래의 경우에서 차이점이 많다.
	good("to be or not to be");
	// 바로불렀을떄는 string의 객체가 없기 떄문에 string 객체를 만들어서
	// 임시 객체를 만들어서 그 객체를 전달하게 된다.

	best("to be or not to be");
	// 임시객체를 불러도 포인터 + 길이 만큼만 있기때문에 바로 접근이 된다.

	// but 읽기만 할수있고 쓰기는 못한다!!

}
