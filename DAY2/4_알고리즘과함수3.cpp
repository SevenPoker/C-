#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9, 8,10};
	
	// 주어진 구간에서 1번째 나오는 "3" 을 찾고 싶다.
    auto ret = std::find(v.begin(), v.end(), 3);


}


