#include <iostream>

// Step 2. 검색 구간의 일반화
// [first, last) 에서 선형 검색수행
// first 는 검색포함, last는 검색 대상 아님 - 반개행 구간(half open range)

char* strchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	char s[] = "abcdefgh";

	char* p = strchr(s, s+4, 'c');
    // 끝을 보내서 중간에서 찾게끔 한다.'
    // 하지만 끝은 검색대상에서 제외된다.

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
