// 3_함수객체1
#include <iostream>

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p; 

	int n = p(1, 2); 
				

	// a + b; 
	// a - b; 
	// a();   
	// a(1,2);
}
