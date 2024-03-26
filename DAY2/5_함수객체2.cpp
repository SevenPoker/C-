#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9, 8,10};
	
	// 주어진 구간에서 1번째 나오는 "3의 배수" 을 찾고 싶다.
    auto ret1 = std::find_if(v.begin(), v.end(), foo);

	int k = 3; // 사용자가 입력한 값이라고 가정.


	// 주어진 구간에서 1번째 나오는 "k의 배수" 을 찾고 싶다.
    // 이항으로 만들고 싶지만 foo는 단항이어야 한다.

    auto ret2 = std::find_if(v.begin(), v.end(), foo);

    // ==> 일반 함수인 foo에서는 main의 지역변수 k를 사용할 수 없다.
    // ==> 결국, 전역변수가 도입되어야한다.

}


