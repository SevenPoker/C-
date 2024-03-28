class Vector
{
public:
    // explicit 생성자 : 직접 초기화만 가능하고 복사 초기화는 사용할 수 없게 할때 사용
	explicit Vector(int sz) {}
};

void foo(Vector v) {}

int main()
{
	// 인자가 한개인 생성자가 있다면 아래 4가지 형태로 객체 생성이 가능합니다.
	Vector v1(10);      // direct initialzation (직접 초기화)
	Vector v2 = 10;     // copy initialzation (복사 초기화)
	Vector v3{10};     // C++11 direct initialization (직접 초기화)
	Vector v4 = {10};  // C++11 copy initialzation (복사 초기화)

	// 함수의 인자 전달은 복사 초기화 과정이다.
	foo(10);
	// error 가 안난다.
	// Vector v = 10 인 형태이다.
	// 따라서 이런형태는 안좋은 형태라서 막아놓는다 (explicit)
}
