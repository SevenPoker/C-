// 1_컨테이너의공통의특징2.cpp
template<typename T>
class Stack 
{
};

class People {};

int main()
{
	Stack<People> s;

	s.push( People() );

	try
	{
		People = s.pop(); // 이 한줄을 생각해 봅시다. (제거와 반환을 동시에 한다면?)
						// 1. stack에서 제거하고
						// 2. 반환하고
						// 3. p = 반환값 에서 복사 생성자 호출.
						//    복사생성자에서 예외가 발생하면??
	}
	catch(...) {}

	// 예외처리 과정에서 나와서 사용 할 때 stack의 마지막 부분이 
	// 이미 제거가 된 상태(데이터 손실)이기 때문에 되돌릴수가 없다.


}

// exception safety(예외 안정성)의 강력 보장
// => 예외가 발생해도, 잡아서 처리했다면
// => 객체의 상태는 예외 이전 상태를 보장한다는 이론
