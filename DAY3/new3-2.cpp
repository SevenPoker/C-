#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Point
{
	int x,y;
public:
	Point(int a, int b) : x(a), y(b) { std::cout << "Point()\n";}
	~Point() { std::cout << "~Point()\n";}
};

template<typename T, typename Ax = std::allocator<T>>
class vector
{
	T* buff;
	std::size_t sz;
	std::size_t capacity;

	Ax ax;

public:
	vector(std::size_t s) : sz(s), capacity(s)
	{
		//buff = new T[sz]; // 이 경우에는 T가 default 생성자 없는 애들은 못만든다!!
							// 제약이 생긴다.
		buff = static_cast<T*>(operator new(sizeof(T)* sz));
		for (int i = 0; i < sz; i++)
		{
			new(&buff[i]) T; // 이렇게 하면 default 생성자가 없으면 말짱 꽝이다!!
			// 위의 new T[sz]랑 같은 이유.
		}
	}

	vector(std::size_t s, const T& value) : sz(s), capacity(s)
	{
		//buff = new T[sz]; // 이 경우에는 T가 default 생성자 없는 애들은 못만든다!!
							// 제약이 생긴다.
		//buff = static_cast<T*>(operator new(sizeof(T)* sz));
		
		buff = ax.allocate(sz); // allocator를 쓴다.

		/*
		for (int i = 0; i < sz; i++)
		{
			new(&buff[i]) T(value);
		}
		*/
		std::uninitialized_fill_n(buff, sz, value);
		// 위의 for문과 동일하게 하는 함수이다.
	}
}

int main()
{
	Point pt(1,1);
	vector<Point> v(10,pt); // 뒤에다가 견본이 되는 생성자를 넘겨줘야한다.
	vector<Point> v(10,Point(0,0));
} 
