
// 2020/3/8 //

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> ShellSort(const vector<int>& vec)
{
    vector<int> vecCopy = vec;
    int len = vec.size();

    int inc = 0, i = 0, j = 0;
    for(inc = len / 2; inc > 0; inc /= 2)
    {
        for(i = inc; i < len; i++)
        {
            int temp = vecCopy[i];
            for(j = i; j >= inc; j -= inc)
            {
                if(vecCopy[j - inc] > temp)
                {
                    vecCopy[j] = vecCopy[j - inc];
                }
                else
                {
                    break;
                }
            }
            vecCopy[j] = temp;
        }
    }

    return vecCopy;
}

int main()
{
    vector<int> sortedVec = ShellSort({6, 7, 2, 1, 0, -4});
    for(auto e : sortedVec)
    {
        cout << e << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}