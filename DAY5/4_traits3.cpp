// 4_traits
#include <iostream>
#include <type_traits> // 이 안에 이미 "std::is_pointer" 있습니다.

template<typename T> void printv(const T& v)
{
	if ( std::is_pointer<T>::value ) // 에러가 나온다. 왜??
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n); // 이 부분에서 에러가 난다.
    // 템플릿은 틀이다.
    // 이거 보내면 컴파일러가 printv( int n ) 과 아래 printv( int* n ) 이 만들어진다.
    // printv 안에 std::is_pointer<T>::value 가 false니까
    // 틀을 찍을때 if (false) 로 찍는다(if는 실행할떄 필요한 함수이기 때문에 그대로 놔둔다.) 근데 그 안에 *v가 있기 때문에
    // 에러가 나는거다
    // else로 빠지면 좋은데.. 그래서 compile에서 결정되게 하자

	printv(&n);
}

