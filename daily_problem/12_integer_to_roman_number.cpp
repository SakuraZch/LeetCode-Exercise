
// 2019/10/9 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::stringstream;
using std::min;
using std::max;

string intToRoman(int num)
{
    map<int, string> romanMap = {{1, "I"}, {4, "IV"}, {5, "V"}, 
    {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, 
    {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"} };
    map<int, string>::reverse_iterator rIter = romanMap.rbegin();
    string result;

    // iterate map reversely
    while(rIter != romanMap.rend())
    {
        if(num >= rIter->first)
        {
            result += rIter->second;
            num -= rIter->first;
        }
        else rIter++;
    }

    return result;
}

string intToRomanSelf(int num)
{
    map<int, string> romanMap = {{1, "I"}, {4, "IV"}, {5, "V"},
     {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, 
     {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
    map<int, string>::reverse_iterator rIter = romanMap.rbegin();
    string result;

    while(rIter != romanMap.rend())
    {
        if(num >= rIter->first)
        {
            num -= rIter->first;
            result += rIter->second;
        }
        else rIter++;
    }

    return result;
}

int main()
{
    string st = intToRomanSelf(3);
    cout << st << endl;
    
    system("pause");
    return 0;
}



