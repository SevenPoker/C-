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

template<typename T, typename R>
void parallel_sum(T first, T last, R& result)
{
    const std::size_t cnt_per_thread = 25;

    const std::size_t cnt_element = std::distance(first, last); // 요소 갯수
    if ( cnt_element == 0) return;

    // thread 당 25개씩 분배할 때 필요한 스레드의 갯수
    const std::size_t max_cnt_thread = (cnt_element + cnt_per_thread -1) / cnt_per_thread;

    // 현재 H/W 상 코어가 몇개 있는가
    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();

    if ( cnt_hw_thread == 0 )
        cnt_hw_thread = 2;

    std::cout << cnt_hw_thread << std::endl;

    // 실제 스레드는 H/W 갯수와 요소의 수를 고려한 숫자중 작은 값
    const std::size_t cnt_thread = std::min(cnt_hw_thread, max_cnt_thread);
    // ----------------------------------------------------------------
    const std::size_t block_size = cnt_element / cnt_thread;

    std::vector<std::thread> thread_vec(cnt_thread-1);
    std::vector<std::thread> result_vec(cnt_thread);

}

int main()
{
    init();

    int s = 0;
//    sum(v.begin(), v.end(), s);
    parallel_sum(v.begin(),v.end(),s);

}
