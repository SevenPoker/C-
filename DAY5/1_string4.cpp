#include <iostream>
#include <string>
#include "show.h"

void foo(const char* s) { std::cout << "const char*\n";} // 1
void foo(const std::string& s) { std::cout << "string";} // 2

int main()
{
	foo("hello"); // ?
}