#include <iostream>

// struct hash가 template라고 알려주는 거다.
template<typename T>
struct Hash;


// template specialization (특수화) 문법
template<>
struct Hash<int>
{
	int operator()(int n) const
	{
		std::cout << "hash for int\n"; 
		return 0;
	}
}

template<>
struct Hash<double>
{
	int operator()(double n) const
	{
		std::cout << "hash for double\n"; 
		return 0;
	}
}


int main()
{
	Hash<int> hi;
	Hash<double> hd;
	int n = h(10);
}