#include <iostream>

template<typename InputIter, typename T>
InputIter find(InputIter first, InputIter last, const T& c)
{
	while (first != last && *first != c)
		++first;

	return first;
}
int main()
{
	double x[10]= {1,2,3,4,5,5,6,67,7,1};

	double* p = find(x, x+4, 5);
}
