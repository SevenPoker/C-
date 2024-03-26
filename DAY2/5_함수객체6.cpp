// 3_함수객체6
// 1. 일반 함수는 자신만의 타입이 없습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.


// 1. 함수 객체는 자신만의 타입이 있습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일해도 모든 함수객체는 다른 타입입니다.

// 함수 객체 : 자신만의 타입을 가지는 함수!!

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

// -----------------------------------------------

// 정책 교체가 가능한데, 정책의 인라인 치환을 지원하는 sort
// => template 과 함수 객체를 사용하는 기술
// => STL 의 설계 철학!! (C++98 시절부터 지원)
template<typename T>
inline void Sort(int* x, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i],x[j]) == true)  
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); Sort(x, 10, f1); // ok
	Greater f2; f2(1, 2); Sort(x, 10, f2); // 


	// template 단점이 있다.
	// template의 경우는 T가 결정이 될때 만들어지기 떄문에
	// Less를 불렀을떄 sort가 하나 만들어지고
	// Greater를 불렀을때 sort가 하나 더 만들어진다.
}



