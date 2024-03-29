#include <iostream>
#include <string>
#include <string_view> // C++17 에서 추가

int main()
{
	// 컴파일할때 문자열을 다 저장한다음에
	// 각 상수 메모리가 거기를 가리키도록 프로그래밍이 되어있다.


	printf("abcde"); // call printf


	std::string s = "to be or not to be"; 
	// 위의 s는 heap에 올라온다.

	// #1. 아래 2줄의 차이점을 알아 두세요
	std::string      ss1 = s; // 깊은 복사
	// 문자열을 복사해온다.(소유권이 있다.)

	std::string_view sv1 = s;
	// sv1은 내부적으로 포인터와 정수 하나를 가지고 있다.
	// 문자열에 대한 view만 제공한다. (소유권이 없다.)


	// #2. 아래 2줄의 차이점을 알아 두세요
	std::string      ss2 = "to be or not to be"; 
    // ss2 는 상수메모리에 있는 to be ~~ 이거를 동적할당으로 
	// 복사[(heap)에 올려서]해서 소유권을 가지고 있다.

	std::string_view sv2 = "to be or not to be"; 
    // sv2는 상수메모리에 있는 to be ~~ 이거를 가리키기만 한다.


	// C언어
	char s1[] = "to be or not to be";
	const char* s2 = "to be or not to be"; // string_view랑 동일기능

}
