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
	char s[] = "abcdefgh";

	char* p = strchr(s, 'c'); // 모든 언어의 끝은 null이기 때문에 끝을 보낼필요는 없다.

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
