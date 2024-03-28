#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 1'000'000;

std::vector<int> v;

void init()
{
    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}
//---------------------------------------------
template<typename T, typename R>
void sum(T first, T last, R& result)
{
    result = std::accumulate(first, last, result);
}

int main()
{
    init();

    int s = 0;
    sum(v.begin(), v.end(), s);
}
