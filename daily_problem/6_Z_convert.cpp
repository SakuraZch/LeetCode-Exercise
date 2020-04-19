
// 2019/10/9 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;
using std::max;

string convert1(string s, int numRows)
{
    if(numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    // * cout << "curRow: " << curRow << endl;
    for(char c : s)
    {
        rows[curRow] += c;
        if(curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
        // * cout << "curRow: " << curRow << endl;
    }
    
    string ret;
    for(string row : rows) ret += row;
    return ret;
}

string convert2(string s, int numRows)
{
    if(numRows == 1) return s;

    string ret;
    int n = s.size();
    int cycleLen = 2 * numRows - 2;

    for(int i = 0; i < numRows; i++)
    {
        // * cout << "i: " << i << endl;
        for(int j = 0; j + i < n; j += cycleLen)
        {
            ret += s[j + i];
            if(i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                ret += s[j + cycleLen - i];
            // * cout << "ret: " << ret << endl;
        }
    }

    return ret;
}

string convertSelf(string s, int rowNum)
{
    if(rowNum == 1) return s;

    vector<string> rows(min(rowNum, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for(char c : s)
    {
        rows[curRow] += c;
        if(curRow == 0 || curRow == rowNum - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }
    
    string output;
    for(string st : rows)
        output += st;
    return output;
}

int main()
{
    string output;
    output = convert1("LEETCODEISHIRING", 3);
    cout << output << endl;
    output = convert2("LEETCODEISHIRING", 4);
    cout << output << endl;
    //output = convertSelf("LEETCODEISHIRING", 3);
    //cout << output << endl;

    system("pause");
    return 0;
}



