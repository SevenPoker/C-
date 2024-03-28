#include <iostream>
#include <string>
#include "show.h"
/*
template< typename CharT,
    	  typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>> 
class basic_string
{
	CharT* buff;
public:
	bool operator==(const basic_string& other)
	{
		return Traits::compare(buff, other.buff);
	}
};
using string = basic_string<char>;
*/

int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	if ( s1 == s2 )
	{
		std::cout << "same" << std::endl;
	}
	else 
	{
		std::cout << "not same" << std::endl;
	}
}