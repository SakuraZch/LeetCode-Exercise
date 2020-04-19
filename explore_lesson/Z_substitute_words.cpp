
// 2019/10/13 //

#include <iostream>
using namespace std;

int main() {

    string s;
    getline(cin, s); // 要处理的字符串

    string s1, s2;
    cin >> s1 >> s2; // 被替换和用于替换的字符串

    string res = ""; // 输出字符串

    for(int i = 0; i < s.size(); i++)
    {
        while(s[i]==' ' && i < s.size()) // 获取非空格字符头，即单词的第一个字母
            i++; 
        int l = i; // 单词的第一个字母对应的下标

        while(s[i] != ' ' && i < s.size()) // 获取非空格字符尾，即单词的最后一个字母
            i++; 
        int r = i-1; // 单词的最后一个字母对应的下标

        string x = ""; // 检测字符串，用来检测目标句子中的单词是不是需要被替换的单词
        for(int j = l; j <= r; j++) // 取单词进行检测
            x += s[j];
    
        if(x == s1) res += s2; // 如果是则将用于替换的单词加入"res"，即输出中
        else res += x; // 如果不是则将原来的单词加入"res"
    
        res += " "; // 用一个空格隔开各个单词
    }

    cout << res.substr(0, res.size()-1); // 去除尾部空格
    
    system("pause");
    return 0;
}
// You want someone to help you
// You
// I