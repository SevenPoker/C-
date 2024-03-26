class Test
{
public:
	enum { value = 1 };
	using DWORD = int;
};
int p = 0;

template<typename T> void foo(T a)
{

	// 클래스이름::이름 에서 이름은
	// 값일수 있고    : enum, static member 등
	// 타입일 수 있다 : using, inner class

	// 아래 2줄에서 * 의 의미를 생각해 보세요(1. 곱하기, 2. 포인터 변수 선언)
	// Test::value * p; // 1 * 전역변수p, 즉, * 는 곱하기의 의미
	// Test::DWORD * p; // 포인터 변수를 선언한거임

	// Dependent name : 템플릿 인자 T에 의존해서 꺼내는 이름
	// => 컴파일러는 무조건 이름의 의미를 값으로 해석합니다.
	T::value* p; // 문제 없음
//	T::DWORD* p2; // 빌드시 error
	typename T::DWORD * p; // ok
							// DWORD를 타입으로 해석해달라는 의미
}
int main()
{
	Test t;
	foo(t);
}
