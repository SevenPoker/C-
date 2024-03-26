#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 }; 
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; 

	x[0] = 10;
	v[0] = 10;
}
