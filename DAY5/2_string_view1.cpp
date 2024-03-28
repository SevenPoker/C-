#include <iostream>
#include <string>
#include <string_view> // C++17 에서 추가

int main()
{
	std::string s = "to be or not to be"; 

	// #1. 아래 2줄의 차이점을 알아 두세요
	std::string      ss1 = s; 
	std::string_view sv1 = s;

	// #2. 아래 2줄의 차이점을 알아 두세요
	std::string      ss2 = "to be or not to be";
	std::string_view sv2 = "to be or not to be";

}
