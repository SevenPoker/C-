// STL 컨테이너의 특징

std::list<int> s = { 1,2,3 };

// 1. 멤버 타입이 있다.
std::list<int>::value_type n = s.front();
std::list<int>::size_type    = s.size();

// 2. 반환과 제거를 동시에 하지 않는다.
int n = s.back();	// 반환만. 제거되지 않는다.
s.pop_back();		// 제거만 한다. 반환 타입은 void

// 3. 단위 전략을 많이 사용한다.
std::list<int, MyAlloc<int>> s2;
std::set<int, greater<int>, MyAlloc<int>> ss;
