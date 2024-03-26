// 3_함수객체7 - 136 page소스
#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준 sort()는 템플릿 입니다.
	// => 사용자가 사용하는 형태에 맞게 코드가 생성된다는 의미


	// 1. 비교 정책으로 일반함수 사용시

	// 장점 : 비교 정책을 여러번 교체해도 sort() 함수는 한개만 생성된다.
	//       => 코드메모리 사용량 감소

	// 단점 : 비교 정책을 담은 함수가 치환될 수 없다. 느리다.
	std::sort(x, x + 10, cmp1); // sort (int*, int*, bool(*)(int,int)) 인 함수가 생성
	std::sort(x, x + 10, cmp2); // sort (int*, int*, bool(*)(int,int)) 인 함수가 생성


	// 2. 비교정책으로 함수객체 사용시

	// 장점 : 비교 정책이 인라인 치환된다. 빠르다.

	// 단점 : 정책 교체 횟수만큼 sort가 생성이 된다.
	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1); // sort(int*, int*, Less) 함수가 생성된다.
 	std::sort(x, x + 10, f2); // sort(int*, int*, Greater) 함수가 생성된다.
}
