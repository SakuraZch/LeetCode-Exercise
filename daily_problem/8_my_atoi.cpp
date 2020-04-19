
// 2019/10/10 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::istringstream;
using std::min;
using std::max;

int myAtoiSelf(string str)
{
    int posNotSpace = str.find_first_not_of(" ");
    
    if(posNotSpace == string::npos || (str[posNotSpace] != '-' && str[posNotSpace] != '+' && !isdigit(str[posNotSpace])))
        return 0;
    int posNumEnd = str.find_first_not_of("0123456789", posNotSpace + 1);
    if(posNumEnd == string::npos)
        posNumEnd == int(str.size()) - 1;

    string numStr = str.substr(posNotSpace, posNumEnd);
    istringstream ss(numStr);
    int targetNum = 0;
    ss >> targetNum;

    return targetNum;
}

int myAtoi(string str)
{
    int num = 0;
    istringstream is(str);
    is >> num;
    return num;
}

int main()
{
    string st = "www-91283472332vds";
    int number = myAtoiSelf(st);
    cout << number << endl;
    
    system("pause");
    return 0;
}



