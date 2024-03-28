#include <memory>
#include <iostream>

struct Freer
{
	void operator()(void* p)
	{
		free(p);
		std::cout << "Freer operator()\n";
	}
};

int main()
{
	// 삭제자 변경
	std::unique_ptr<int> up1(new int);			// ok
//	std::unique_ptr<int> up2(new int[10]);		// 버그. 소멸자가 delete 라서 안됨
												// delete[] 만 가능
  
	std::unique_ptr<int[]> up2(new int[10]); // ok
											// C++14 부터 가능하다.

	// ------------------------------------------------
	// 삭제자를 변경할려면?
	// => 템플릿 2번째 인자로 삭제 방법을 담은 함수 객체를 전달해야한다.
	std::unique_ptr<int, Freer> up3(static_cast<int*>(malloc(sizeof(int)));


	// shared_ptr vs unique_ptr
	
	std::shared_ptr<int> sp(malloc 할당, 삭제자 전달);
	std::unique_ptr<int, 삭제자> up(malloc 할당);

	// shared_ptr : control block 이 있으므로 삭제자 저장하면 됩니다.
	// unique_ptr : 삭제자를 위한 저장공간이 없어도 된다. 아래코드 참조.
	//              그냥 삭제자를 객체 받아서 그거 불러서 쓰면 된다.

	// shared_ptr은 삭제자를 변경해도 같은 타입 (같은 container에 넣을수있다.)

	// unique_ptr은 삭제자를 변경하면 다른 타입 (안된다)

}

template<typename T, typename Dx = std::default_delete<T>>
class unique_ptr
{
	T* ptr; // 자원 포인터
public:
	~unique_ptr()
	{
		Dx d; // 삭제자 함수객체 생성
		d(ptr); // 삭제
	}
}
