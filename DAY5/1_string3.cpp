#include <iostream>
#include <string>
#include "show.h"

using dstring = std::basic_string<char, std::char_traits<char>, debug_alloc<char>>;

int main()
{
	for(int i = 0; i < 20; i++)
	{
		std::cout << i << std::endl;
		dstring s(i, 'A');
	}
}