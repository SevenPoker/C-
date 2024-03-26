#include <iostream>
#include <vector>
#include <algorithm>

// 조건자(predicate) : 반환값이 bool 이거나
//                             bool 로 변환가능한 타입을 반환하는 함수
// xxx_if 로 끝나는 알고리즘은 "조건자"를 보내야 합니다.
// std::find_if : 3번째 인자로 "unary predicate" 요구

bool foo(int n) { return n % 3 == 0;}

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9,8,10};
	
	// 주어진 구간에서 1번째 나오는 "3" 을 찾고 싶다.
    auto ret1 = std::find(v.begin(), v.end(), 3);


	// 주어진 구간에서 1번째 나오는 "3의 배수" 을 찾고 싶다.
    auto ret2 = std::find_if(v.begin(), v.end(), foo);


    // std::find : 값 검색, 3번째 인자로 "값" 전달
    // std::find_if : 조건 검색, 3번째 인자로 "함수(단항조건자)" 전달


}


