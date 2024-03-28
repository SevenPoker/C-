#include <iostream>
#include <string>
#include "show.h"

// STL : Standart "Template" Library

/*
template< typename CharT,
    	  typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>> 
class basic_string
{
};
using string = basic_string<char>;
using wstring = basic_string<wchar_t>;
*/

int main()
{
	std::string s = "hello";		// ansi 문자열
	std::wstring ws =L"hello";		// unicode 문자열
}
