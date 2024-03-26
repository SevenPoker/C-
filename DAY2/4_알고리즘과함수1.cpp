#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    // for_each 알고리즘
    std::for_each(v.begin(), v.end(), foo);


	return 0;
}



















//
