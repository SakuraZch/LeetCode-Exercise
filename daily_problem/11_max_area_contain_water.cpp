
// 2019/10/9 //

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
using std::min;
using std::max;

int maxAreaSelf(vector<int>& height)
{
    if(int(height.size()) == 2)
        return min(height[0], height[1]);

    int maxVal = 0;
    for(int i = 0; i < int(height.size()); i++)
    {
        int tempVal = 0;
        for(int j = i + 1; j < int(height.size()); j++)
        {
            tempVal = min(height[i], height[j]) * (j - i);
            maxVal = max(maxVal, tempVal);
        }
    }
    cout << maxVal << endl;
    return maxVal;
}

int maxArea(vector<int>& height)
{
    int i = 0, j = int(height.size()) - 1, maxVal = 0;
    while(i < j)
    {
        int buttom = j - i;
        if(height[i] < height[j])
        {
            maxVal = max(maxVal, height[i] * buttom);
            i++;
        }
        else
        {
            maxVal = max(maxVal, height[j] * buttom);
            j--;
        }
    }

    return maxVal;
}

int main()
{
    vector<int> vt = {1,8,6,2,5,4,8,3,7};
    int result = maxArea(vt); 
    cout << result << endl;
    system("pause");
    return 0;
}



