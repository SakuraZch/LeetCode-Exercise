
// 2019/10/8 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

int lenOfPalindrome(string& st, int pos)
{
    int i = 0, j = 0;
    int len1 = 0, len2 = 0;
    for(i = pos, j = pos; i >= 0 && j < st.size() && st[i] == st[j]; i--, j++)
        len1 = j - i + 1;
    for(i = pos, j = pos + 1; i >= 0 && j < st.size() && st[i] == st[j]; i--, j++)
        len2 = j - i + 1;
    return max(len1, len2);
}

string longestPalindrome(string st)
{
    if(st.size() == 0 || st.size() == 1)
        return st;

    string pStr;
    int maxLen = 1;
    int start = 0;
    for(int i = 0; i < st.size(); i++)
    {
        int tempLen = lenOfPalindrome(st, i);
        if(maxLen < tempLen)
        {
            maxLen = tempLen;
            start = i - (maxLen - 1) / 2;
        }
    }
    return st.substr(start, maxLen);
}

int main()
{
    string stTest = "adscdbdcsdf";
    string result = longestPalindrome(stTest);
    cout << result << endl;
    system("pause");
    return 0;
}

