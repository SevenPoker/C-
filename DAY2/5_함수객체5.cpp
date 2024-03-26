#include <iostream>
#include <algorithm> 

// 137page 아래부분


// 아래처럼 sort를 구성하면 내림차순으로는 못한다!

/*
void Sort(int* x, int sz )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (x[i] > x[j])  
				std::swap(x[i], x[j]);
		}
	}
}
*/

// 그래서 함수 포인터를 받는게 C언어의 정책!!
// 핵심 : 함수 인자로 비교 정책을 담은 함수를 받아서 사용

// 장점 : 비교 정책의 교체가 되므로 유연성이 좋다.
// 단점 : 비교시 다시 함수를 호출하게 되므로 느리다.
//        cmp1, cmp2를 inline 으로 해도 '함수포인터에 담아서 사용'
//        하므로 치환될 수 없다.

// 비교 정책 교체가 가능한데!! 인라인 치환이 되게 할 수는 없을까??
// => C언어로는 안됨
// => STL은 됨


void Sort(int* x, int sz, bool(*cmp)(int, int) )
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

// ------------------------------
// 비교 정책으로 사용할 이항함수
bool cmp1(int a, int b) { return a < b;}
bool cmp2(int a, int b) { return a > b;}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	//Sort(x, 10);
	Sort(x,10,cmp2); 
	// 이렇게 바꾸면 정책을 바꿀수는 있지만 코드가 위의 origin sort보다 너무 느리다.
	// (cmp(x[i],x[j]) == true) 이거가 개많이 불린다.
	// inline을 써도 함수 포인터에 담았기 때문에 치환이 되지않는다.

}

