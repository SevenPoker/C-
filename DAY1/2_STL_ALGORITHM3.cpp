#include <iostream>

// Step 3. 검색 대상 타입의 일반화 - template 도입
// 함수 이름 변경 : strchr => find

template<typename T>
T* find(T* first, T* last, T c)
{
	while (first != last && *first != c)
		++first;

	return first == last ? nullptr : first;
}

int main()
{
	double x[10]= {1,2,3,4,5,5,6,67,7,1};

	double* p = find(x, x+100, 5.0);
    // 끝을 보내서 중간에서 찾게끔 한다.'
    // 하지만 끝은 검색대상에서 제외된다.

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
