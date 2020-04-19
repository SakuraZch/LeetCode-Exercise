
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
using std::abs;

int threeSumClosest(vector<int>& nums, int target)
{
    int size = int(nums.size());
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[size - 1];
    if(size == 3) return nums[0] + nums[1] + nums[2];

    for(int k = 0; k <= size - 3; k++)
    {
        int i = k + 1, j = size - 1;
        while(i < j)
        {
            int sumNum = nums[i] + nums[j] + nums[k];
            int diff = target - sumNum;
            if(abs(sumNum - target) < abs(res - target)) res = sumNum;
            if(diff == 0) return target;
            else if(diff > 0) i++;
            else if(diff < 0) j--;
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    int sum = threeSumClosest(nums, target);
    cout << sum << endl;
    
    system("pause");
    return 0;
}



