
// 2019/10/9 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::iterator;
using std::min;
using std::max;

void printReverseSelf(const string& s, int idx = -1)
{
    char ch = s[idx];
    if(idx >= 0)
    {
        cout << ch;
        printReverseSelf(s, idx - 1);
    }
    return ;
}

void printReverseC(const char* str)
{
    if(!*str)
        return ;
    printReverseC(str + 1);
    putchar(*str);
}

void printReverseCpp(const string& s, string::iterator str)
{
    if(str == s.end())
        return ;
    printReverseCpp(s, str + 1);
    putchar(*str);
}

int main()
{
    string st = "abcdef";
    printReverseSelf(st, int(st.size() - 1));
    cout << endl;
    printReverseC(st.c_str());
    cout << endl;
    string::iterator ite = st.begin();
    printReverseCpp(st, ite);
    cout << endl;
    system("pause");
    return 0;
}



