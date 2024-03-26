#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

struct IsDivide
{
    int value;

    IsDivide(int n) : value(n) {}

    bool operator()(int n) { return n % value == 0; }
};

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9, 8,10};
	
	int k = 3;

    IsDivide f(k);
    // 1. f는 내부적으로 k값을 보관합니다. (k값 캡쳐)
    // 2. f는 함수처럼 사용가능하다 (단항함수)
    bool b = f(10);
    // 10 % k 의 의미

//    auto ret1 = std::find_if(v.begin(), v.end(), foo); // 단항함수만 전달
    auto ret1 = std::find_if(v.begin(), v.end(), f);
    // 단항함수+k 값 을 전달하는 의미


}

// 일반 함수 : 동작은 있지만, 상태가 없다.
//            함수 수행중 결정된 데이터등을 보관할 장소가 없다.

// 함수 객체 : 동작뿐 아니라, 상태가 있다. (멤버 데이터가 있다는 의미)

// closure(클로져) : 현재 문맥 (main 함수)이 가진 지역변수를 캡쳐할수 있는 함수.

// 함수 객체는 "클로저가 될수있지만"
// 일반 함수는 "클로저가 될 수 없다"

// 함수를 다른 곳에 인자로 보낼때 "함수 + 지역변수"를 같이 보내기 위해 사용
// 하는 것이 "클로저"

// C++, java, C#, rust, swift 등 대부분의 언어에 클로져 개념 사용
