#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9, 8,10};
	
	int k = 3;

	// 주어진 구간에서 1번째 나오는 "k의 배수" 을 찾고 싶다.

    // 람다 표현식은 "지역변수를 캡쳐 " 할 수 있다.
	// [k] : 람다표현식에서 k를 사용하겠다는 의미
	auto ret1 = std::find_if(v.begin(), v.end(),
					[k](int n){return n % k == 0;});

	// ----------------------------------
	// compiler가 아래처럼 코드를 만들어 준다.

	class CompilerGeneratedName
	{
		int k; // 람다 표현식에서 갭쳐를 사용하면 멤버 데이터가 추가가 된다.
	public:
		CompilerGeneratedName(int n) : k(n){}
		inline auto operator()(int n) const
		{
			return n % k == 0;
		} 
	};

	auto ret1 = std::find_if(v.begin(), v.end(),CompilerGeneratedName(k));
	// 결국 함수객체3.cpp 에서 만든 "IsDivide" 와 동일한 원리이다.
}


