
// 2019/10/7 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::max;

int lengthOfLongestSubstring1(string st)
{
    if(int(st.length()) == 1 || int(st.length()) == 0)
        return int(st.length());

    int len = int(st.length());
    int maxLen = 0;
    for(int i = 0; i < len; i++)
    {
        string tempStr;
        for(int j = i; j < len; j++)
        {
            int idx = tempStr.find(st[j]);
            if(idx == string::npos)
                tempStr += st[j];
            if(idx != string::npos || j == len - 1)
            {
                maxLen = max(maxLen, int(tempStr.length()));
                break;
            }
        }
    }

    return maxLen;
}

int lengthOfLongestSubstring2(string st)
{
    if(st.size() == 0 || st.size() == 1) 
        return st.size();

    unordered_set<char> lookup;
    int maxStr = 0, left = 0;
    for(int i = 0; i < st.size(); i++)
    {
        while(lookup.find(st[i]) != lookup.end()) // "st[i]" inside "lookup" set
        {
            // * cout << "st[left]: " << st[left] << " i: " << i << endl;
            lookup.erase(st[left]); // erase element at the left site
            left++; // "left" pointer step forward
        }
        maxStr = max(maxStr, i - left + 1); // store max length
        // * cout << "st[i]: " << st[i] << " length: " << maxStr << endl;
        lookup.insert(st[i]); // "st[i]" outside "lookup" set, insert it inside
    }

    return maxStr;
}

char findSingleElement(string st)
{
    if(st.size() == 0 || st.size() == 1)
        return st[0];

    unordered_set<char> lookup;
    int maxStr = 0, left = 0;
    for(int i = 0; i < st.size(); i++)
    {
        while(lookup.find(st[i]) != lookup.end()) // "st[i]" inside "lookup" set
        {
            lookup.erase(st[i]); // erase element at the left site
            left++; // "left" pointer step forward
        }
        lookup.insert(st[i]); // "st[i]" outside "lookup" set, insert it inside
    }
    for(auto i : lookup)
        cout << "A:" << i << endl;
    return ' ';
}

int main()
{
    int maxLen = lengthOfLongestSubstring1("pwwkew");
    cout << maxLen << endl;
    string st2 = "zdzkbzkb";
    cout << st2 << endl;
    maxLen = lengthOfLongestSubstring2(st2);
    cout << maxLen << endl;
    string st3 = "1212344";
    char result = findSingleElement(st3);
    cout << result << endl;
    system("pause");
    return 0;
}

