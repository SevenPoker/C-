#include <iostream>
#include <string>
#include <string_view>

void bad(std::string s) { }
void good(const std::string& s) {}
void best(std::string_view   s) {}

int main()
{
	std::string s = "to be or not to be";

	good(s);
	best(s);
}
