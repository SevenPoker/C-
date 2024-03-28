#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  sp1(new int); // ok, sp1의 소멸자가 delete


	std::shared_ptr<int>  sp2( static_cast<int*> (malloc(sizeof(int))) );
							// 잘못된 코드, 소멸자에서 free가 아닌 delete가 불려서 호환이 안된다.

	std::shared_ptr<int> sp3((int*)malloc(sizeof(int)), foo); // ok
							// ok. sp3 파괴시 소멸자에서 foo 호출
	
	std::shared_ptr<int> sp4((int*)malloc(sizeof(int)), free); 


	// -----------------------------------------------------------
	// 배열로 할당
	std::shared_ptr<int> sp5( new int[10]); // 버그, 잘못된 코드
											// delete가 아닌 deletep[] 필요
	
	std::shared_ptr<int> sp6(new int[10], [](int p*){delete[] p ;});// ok

	// C++17 부터는 아래처럼 사용하면 된다.
	std::shared_ptr<int[]> sp7(new int[10]);

	// 그런데, new int[10]이 필요하면 vector가 더 좋지 않을까!?
	// => 권장
	//---------------------------------------------------
	// 아래 처럼도 가능하지만 사용하지는 말자
	// 파일을 자동으로 열고 닫게도 해준다...
//	std::shared_ptr<FILE*> sp8(fopen("a.txt","rw"), fclose);

	// std::make_shared 를 사용하면 자원할당 방법 자체를 변경할 수 없다.
	std::shared_ptr<int> sp9 = std::make_shared<int>();



}
