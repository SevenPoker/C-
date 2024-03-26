#include <iostream>
#include <algorithm> 

// 137page 아래부분


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

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10);
}

