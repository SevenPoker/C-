#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b){ return a < b;});

	// -------------------------------------
	// 람다표현식의 원리
	// => 위 코드를 컴파일러가 아래 코드처럼 변경해준다.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b)
		{
			return a < b;
		}
	};
	std::sort(v.begin(), v.end(), CompilerGeneratedName());

	return 0;
}

// cppinsights.io
