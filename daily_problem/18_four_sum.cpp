
// 2019/10/17 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::stringstream;
using std::min;
using std::max;

vector<vector<int>> fourSumSelf(vector<int>& nums, int target)
{
    vector<vector<int> > res;
    int size = nums.size();

    sort(nums.begin(), nums.end());
    if(size == 4 && nums[0] + nums[1] + nums[2] + nums[3] == target)
    {
        res.push_back({nums[0], nums[1], nums[2], nums[3]});
        return res;
    }

    for(int firstIdx = 0; firstIdx < size - 3; firstIdx++)
    {
        if(nums[firstIdx] > target && target > 0) break;
        int secondIdx = firstIdx + 1;
        int thirdIdx = size - 2;
        int fourthIdx = thirdIdx + 1;
        while(secondIdx < thirdIdx)
        {
            int tempSum = nums[firstIdx] + nums[secondIdx] + nums[thirdIdx] + nums[fourthIdx];
            int count = 0;
            if(tempSum > target)
            {
                if(secondIdx < thirdIdx) thirdIdx--;
                if(fourthIdx - thirdIdx >= 2) fourthIdx--;
            }
            else if(tempSum < target) secondIdx++;
            else
            {
                res.push_back({nums[firstIdx], nums[secondIdx], nums[thirdIdx], nums[fourthIdx]});
                secondIdx++;
                thirdIdx--;

            }
        }
    }

    return res;
}


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int> > res;
    set<vector<int> > deRepSet;
    int size = nums.size();

    if(size < 4 || size == 4 && nums[0] + nums[1] + nums[2] + nums[3] != target) return res;
    else if(size == 4 && nums[0] + nums[1] + nums[2] + nums[3] == target)
    {
        res.push_back({nums[0], nums[1], nums[2], nums[3]});
        return res;
    }

    sort(nums.begin(), nums.end());

    for(int firstIdx = 0; firstIdx < size - 3; firstIdx++)
    {
        if(nums[firstIdx] > target && target > 0) break;
        for(int secondIdx = firstIdx + 1; secondIdx < size - 2; secondIdx++)
        {
            int thirdIdx = secondIdx + 1;
            int fourthIdx = size - 1;
            while(thirdIdx < fourthIdx)
            {
                int tempSum = nums[firstIdx] + nums[secondIdx] + nums[thirdIdx] + nums[fourthIdx];
                if(tempSum < target) thirdIdx++;
                else if(tempSum > target) fourthIdx--;
                else
                {
                    vector<int> tempVec = {nums[firstIdx], nums[secondIdx], nums[thirdIdx], nums[fourthIdx]};
                    deRepSet.insert(tempVec);
                    while(thirdIdx < fourthIdx && nums[thirdIdx] == nums[thirdIdx + 1]) thirdIdx++;
                    while(thirdIdx < fourthIdx && nums[fourthIdx] == nums[fourthIdx - 1]) fourthIdx--;
                    thirdIdx++;
                    fourthIdx--;
                }
            }
        }
    }
    for(auto vt : deRepSet) res.push_back(vt);
    
    return res;
}

int main()
{
    vector<vector<int> > res;
    vector<int> testVec = {-3,-1,0,2,4,5};
    int target = 0;
    res = fourSum(testVec, target);
    for(auto i : res)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    
    system("pause");
    return 0;
}



