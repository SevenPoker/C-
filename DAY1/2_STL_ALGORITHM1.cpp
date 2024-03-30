#include <iostream>

// Step 1. C 표준 함수
char* strchr(char* s, int c)
{
	while (*s != 0 && *s != c)
		++s;
	return *s == 0 ? 0 : s;
}
int main()
{
	char s[] = "abcdefgh"; // char형 배열로 저장이 되는것이기 때문에 변경 가능하다.
//	char* s1 = "ddkvqniq"; // 컴파일시에 .data영역에 "ddkvqniq"가 올리고 그 주소를 가리키게 해놓은 거다.
	// 따라서 변경 가능하지 않다.


	// strchr : 문자열에서 문자를 찾는 C 표준 함수
	char* p = strchr(s, 'c');

	s[0] = 'k';
//	*s1 = "dddd"; // error

	std::cout << s[0] << std::endl;

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
