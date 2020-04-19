
// 2019/10/14 //

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

vector<vector<int> > threeSum1(vector<int>& nums)
{
    vector<vector<int> > res;
    set<vector<int>> ret; // 用来去重
    
    if(nums.size() < 3)
        return {};
    
    for(int i = 0; i < int(nums.size()) - 2; i++)
    {
        for(int j = i + 1; j < int(nums.size()) - 1; j++)
        {
            for(int k = j + 1; k < int(nums.size()); k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp;
                    int a = (nums[i] < nums[j] ? nums[i] : nums[j]) < nums[k] ? (nums[i] < nums[j] ? nums[i] : nums[j]) : nums[k];//放最小的元素
                    int b = (nums[i] > nums[j] ? nums[i] : nums[j]) > nums[k] ? (nums[i] > nums[j] ? nums[i] : nums[j]) : nums[k];//放最大的元素
                    int c = 0 - a - b;
                    temp.push_back(a);
                    temp.push_back(c);
                    temp.push_back(b);
                    ret.insert(temp);
                }
            }
        }
    }

    for(auto it : ret)
        res.push_back(it);
    
    return res;
}

vector<vector<int> > threeSum2(vector<int>& nums)
{
    vector<vector<int> > res;
    int size = int(nums.size());

    sort(nums.begin(), nums.end()); // if the vector is unsorted, we can not use method of three pointers
    if(size < 3 || nums.front() > 0 || nums.back() < 0) return res; // directly return

    int i = 0, j = 0, k = 0; // three pointers
    for(k = 0; k <= size - 3; k++)
    {
        if(nums[k] > 0) break; // if "nums[k]" is bigger than zero, the sum of three nums must not be zero
        if(k > 0 && nums[k] == nums[k - 1]) continue; // jump repetition
        i = k + 1; // left pointer
        j = size - 1; // right pointer
        while(i < j)
        {
            if(nums[i] + nums[j] + nums[k] > 0) j--; // sum bigger than zero, meaning that a number should be smaller
            else if(nums[i] + nums[j] + nums[k] < 0) i++; // sounds like the sentence before
            else // sum equal to zero, we have to deal with repetition situations
            {
                res.push_back({nums[i], nums[j], nums[k]}); // store tuple
                while(i < j && nums[i] == nums[i + 1]) i++; // jump repetition
                while(i < j && nums[j] == nums[j - 1]) j--;
                i++; // remove pointer to the location without repetition
                j--;
            }
            // * cout << "k: " << k << " i: " << i << " j: " << j << endl;
        }
    }

    return res;
}

int main()
{
    
    vector<int> testData = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int> > result = threeSum2(testData);
    for(vector<int> vt : result)
    {
        for(int num : vt)
            cout << num << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}



