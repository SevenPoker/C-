#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include "show.h"

int main()
{
    std::ifstream fin("7_map2.cpp");
    std::string s;
    int no = 0;

    std::string word;
    std::map<std::string, std::vector<int>> index;
    // 자료구조를 생각해보자

    while(std::getline(fin, s)) // getline을 하면 문장 전체를 읽어온다.
    {
        ++no;
        std::istringstream iss(s);
        
        while( iss >> word)
        {
            index[word].push_back(no); // 없으면 만들어라
        }
    }
    // =========================

    for (const auto& [key, value] : index)
    {
        std::cout << key << " : ";
        show(value);
    }


}


