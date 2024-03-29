#include <stdio.h>

int x = 100;

int main()
{
//  char* s3 = "ABCD"// C언어는 이 코드가 에러가 안남.
                      // 하지만 C++ 에서는 const가 없으면 compile 에러
//  *s3 = 'X'; // C언어 실행시 에러
               // compile 할떄 에러가 안남

    const char* s1 = "ABCD";
    const char* s2 = "XYZ";

    printf("ABCD");
}

// 1. 빌드해서 실행파일 만들고
// 2. 구글에서 "PEView" 검색
// 3. PEView 실행해서 실행파일 열자.

// 실행파일은
// 앞부분은 header (날짜, ~~컴파일로 쓰고~~)
// .text 에 기계어 코드가 있다.
// 전역변수 초기값들이 .data에 저장된다.static 지역변수도 들어가있다.
// 문자열들은 .rdata(read only) 에 저장된다. 링커는 각각 문자열들의 주소를 가지고 있다.


// 실행파일을 수행하면
// .text 가 올라오고
// .data가 stack에 올라온다.
// .rdata
