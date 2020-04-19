
// 2019/10/16 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cctype>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::queue;
using std::stringstream;
using std::min;
using std::max;

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    int size = digits.size();
    queue<string> que;

    for(int j = 0; j < int(mp[digits[0]].size()); j++)
    {
        string str;
        str.push_back(mp[digits[0]][j]);
        que.push(str);
    }
    for(int i = 1; i < size; i++)
    {
        int length = que.size();

        while(length--)
        {
            // cout << "front: " << que.front() << endl;
            for(int j = 0; j < int(mp[digits[i]].size()); j++)
            {
                string s = que.front();
                // cout << "ele: " << mp[digits[i]][j] << endl;
                s += mp[digits[i]][j];
                que.push(s);
            }
            que.pop();
        }
    }
    while(!que.empty())
    {
        res.push_back(que.front());
        que.pop();
    }
    
    return res;
}

int main()
{
    vector<string> result = letterCombinations("234");
    for(auto i : result) cout << i << endl;
    
    system("pause");
    return 0;
}



