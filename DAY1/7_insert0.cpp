//

template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T>
class List
{
public:
	List(int sz, T value){}
};

// C++14 까지는 클래스 템플릿의 타입 추론이 안되므로 복잡해 보이는 경우가 있습니다.
// 이 경우, 아래 기법을 사용하는 경우가 많다.
// 클래스 템플릿의 객체를 생성하는 함수 템플릿!!
// "object generator" 라고 불리는 기술.. 클래스템플릿의 객체를 만드는 함수 템플릿
// 구글 "C++ IDioms" 검색

template<typename T>
List<T> make_list(int sz, T value)
{
	return List<T>(sz,value);
}

int main()
{
	square<int>(3); // 정확한 표기법
	square(3); // 타입 파라미터 생략 가능. 인자 3으로 T 타입 추론

	List<int> s1(10,3);
	//List	  s2(10,3); // 클래스템플릿의 경우 생성자를 통한 타입추론은 C++17 이후부터 가능.

	auto s3 = make_list<int>(10,3); // 정확한 표기법
}

// g++ 7_insert