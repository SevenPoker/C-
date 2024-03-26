// 1_STL_PREVIEW1
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{

	// 컨테이너 : 여러개의 요소를 보관하는 자료구조

	vector<int> v = {1,2,3,4,5};
	// vector 는 연속적으로 되어있다.
    // 그래서 중간 삽입을 하면 속도가 떨어질 수 있다.
	// 끝에다가 넣을려면 벡터가 훠얼씬 빠르다. 20배 정도 빠름

	list<int> s = {1,2,3,4,5};
	// 모든 요소가 떨어진 메모리에 저장이 된다.
	// 중간 삽입이 많아질때는 이걸로 써야한다.

	// C++ 17 부터는 타입을 생략할 수있다.
	// vector v2 = {1,2,3,4,5};
	// vector v3{1,2,3,4,5,6};




}
