#include <map>  
#include "show.h"

// map : pair 를 저장하는 set,   key 값으로 value 를 저장

int main()
{
	std::map<std::string, std::string> m = { {"mon", "월요일"}, {"tue", "화요일"}};

	// #1. 요소 넣기
	// 1. pair 만들어서 넣기
//	std::pair<std::string, std::string> p("wed", "수요일");
//	m.insert(p);

	// 2. make_pair
//	m.insert( std::make_pair("wed", "수요일"));

	// 3. emplace
	m.emplace("wed", "수요일"); // 자세한 내용은 "사용자 정의타입" 주제에서

	// 4. [] 연산자 사용
	m["thu"] = "목요일";
//	m["thu"] = "목"; // 기존 키값에 해당하는 value 를 변경한것
	//------------------------
	
	// #2. 반복자에 대해서
	auto p = m.find("wed"); // find(키값)

	// p를 사용해서 "wed : 수요일" 이라고 출력해보세요

	std::cout << p->first << ": " << p->second << std::endl;

	// #3.for 와 map
//	for( auto e : m) // e는 std::pair 인데 복사본 생성된것
	for(const auto& e : m)
	{
		std::string key = e.first;
		std::string value = e.second;
	}

	// 복사본이 만들어지지 않았다.
	// C++17 이후부터는 아래처럼 하는게 좋다.
	// structure binding 기법
	// m 이 return 값이 make_pair 라서 가능하다 (아래 참조를 보면 된다.)
	for(const auto& [key, value] : m)
	{
	}


	// #4. [] 연산자
	std::cout << m["sun"] << std::endl; 
	// 1. 키값 "sun" 이 있다면 value 반환
	// 2. 키값 "sun" 이 없다면 ["sun",""]으로 새로운 항목을 추가한다.

	// 키값이 있는지 조사할때 절대 아래처럼 하면 안된다.
	if ( m["sun"] == "") {} // 키값을 생성한것이다....

	auto ret2 = m.find("sun");
	if (ret2 == m.end()) {}

	// C++20 부터
	if (m.contains("sun")) {} // 내부 원리는 위와 동일

}
// 참고
/*
	Point pt;
	int a = pt.x;
	int b = pt.y;

	// C++17 부터 아래 코드가 지원된다. (structure binding)
	auto[a,b] = pt;	// auto만 가능 (다만 return 갯수가 같아야한다, 순서대로 꺼낸다.)
	auto[error, value] = foo();


std::tuple<int,int> foo()
{
	return std::make_tuple(10,20);
}
*/
