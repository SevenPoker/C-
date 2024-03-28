#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

// system_clock : 현재 시간을 얻을때 사용하는 클래스, non monotonic clock
// time_point   : 시간의 시작점과 duration<>을 보관하는 클래스
//				  ex) 1970년 1월 1일 기준 16880 시간 경과


// epoch_time : 시간의 시작점을 "1970년 1월 1일" 로 하는 시간

int main()
{
	// 1. 현재 시간을 얻는 방법
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();


	// 2. time_point => duration 얻어내기... 정밀도가 낮아지는 경우 명시적 캐스팅 필요..
	std::chrono::nanoseconds nanosec = tp.time_since_epoch();
	std::chrono::seconds     sec     = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());

	std::cout << nanosec.count() << std::endl;
	std::cout << sec.count() << std::endl;

	// c++20 부터는 days 타입이 있지만 c++ 이전에는 아래처럼 만들어서 사용
	using days = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;
	std::cout << std::chrono::duration_cast<days>(tp.time_since_epoch()).count() << std::endl;


	// 3. time_point => 칼린더 형태의 날짜로 변경하기
	time_t t = std::chrono::system_clock::to_time_t(tp); // 1. time_point => struct time_t
	std::string s = ctime(&t);					// 2. struct time_t => char*
	std::cout << s << std::endl;

}



