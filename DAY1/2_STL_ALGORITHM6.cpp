#include <iostream>
#include <algorithm> // 이 안에 find 함수가 있다.
                     // 아래 코드와 거의 동일한 코드이다.
// find 정리
// 하는 일 : [first, last) 구간에서 선형 검색 수행

// 구간의 표현 : 반드시 포인터일 필요는 없다.
// 구간의 이동 : 전위형 ++ 연산자
// 검색 실패시 : last 반환

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;
}

int main()
{
	double x[10]= {1,2,3,4,5,5,6,67,7,1};

	double* p1 = std::find(x, x+3, 5);

    std::cout << *p1 <<std::endl;
    double* p2 = find(x, x+3, 5);
    std::cout << *p2 <<std::endl;
}
