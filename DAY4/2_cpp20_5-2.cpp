#include <string> 
#include <algorithm>
#include <functional>
#include <iostream>

struct Point
{
	int x,y;

	int gety() const {return y;} // 멤버함수
};

int gety(const Point& p) {return p.y; } // 일반 단항 함수

int main()
{
	Point p1 = {1,1};
	Point p2 = {1,2};

	//auto ret1 = std::ranges::max(p1,p2); // error

	auto ret2 = std::ranges::max(p1,p2,{},&Point::gety); // projection으로 멤버함수 사용

	auto ret3 = std::ranges::max(p1,p2,{},&gety); // 일반 함수 사용

	auto ret4 = std::ranges::max(p1,p2,{},&Point::y); // public 멤버 데이터 주소

        auto ret5 = std::ranges::max(p1,p2,{},[](Point p){return p.y;});

	// projection 에는
	// 1. public 멤버 데이터의 주소
	// 2. 인자가 없는 멤버함수 주소
	// 3. 인자가 한개(p1, p2 라면 인자가 Point인)인 일반함수(객체), 람다표현식
}
