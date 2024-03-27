#include <vector>

template<typename T> 
class Queue 
{
	std::vector<T> v;

public:
	void pop() { v.pop_front(); }
};

int main()
{
	Queue<int> q;
}