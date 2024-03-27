
#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 1. 생성
	std::vector<int> v1;
	std::vector<int> v2(10);	// 10개를 0으로
	std::vector<int> v3(10, 3); // 10개를 3으로 
	std::vector<int> v4(v3);    // v3 와 동일

	std::vector<int> v5{ 10, 3 }; // 2개를 10, 3으로
	// 중괄호를 쳤을떄는 원소를 나타낸다.
	
	std::vector<int> v6 = { 1,2,3 }; // 이것처럼 위의 v5를 쓰면되지만
	// 대부분 v5와 같은 문법을 쓴다.
	

	// 2. 삽입, 
	v1.push_back(0);
	v1.push_front(0); // 단 vector는 안된다.
//	v1.insert(위치를 나타내는 반복자, 0); // 반복자 앞에 넣기

	// 3. 접근
	int n1 = v1.front();
	int n2 = v1.back();
	int n3 = v1[3]; // list는 안됨    (예외가 안나오고)
	int n4 = v1.at(); // list는 안됨  (예외가 나오고)

	// 4. 요소 제거
	v1.pop_back(); // 끝부분 제거
	v1.pop_front(); // vector는 안됨

	v1.erase(반복자A);				// 한개 제거
	v1.erase(반복자A, 반복자B);		// 구간 제거

	// 5. 요소 전부 교체
	v1.assign(v2.begin(), v2.end()); // v1 = v2의 의미이지만 v1=v2는 같은 타입일때 가능
	// assign을 만든 이유는 다른 container 끼리 복사를 가능하게 하기 위해서
	// ex) list와 vector
}
