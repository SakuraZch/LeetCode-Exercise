
// 2020/2/10 //

#include "0_linklist.h"

#include <vector>

using std::vector;

// ? split initial list
vector<ListNode*> splitListToParts(ListNode* root, int k)
{
    int len = getListLen(root); // get list length
    int avgLen = len / k, mod = len % k; // get list-split parameters
    vector<ListNode*> res(k, nullptr); // result vector

    ListNode* prev = nullptr; // previous pointer
    ListNode* curr = root; // current pointer
    for(int i = 0; i < k; i++) // cut "k" times
    {
        res[i] = curr; // pointer "curr" indicate head of each divided-list
        int temp_len = mod ? avgLen + 1 : avgLen; // calculate temporary length according to the counter "mod"
        while(temp_len--) // link "temp_len" times
        {
            prev = curr;
            curr = curr->next;
        }

        if(prev != nullptr) // tail of divided-list
        {
            prev->next = nullptr; // do split
        }
        if(mod > 0) // control the number of longer divided-list
        {
            mod--; // longer divided-list counter subtract one
        }
    }

    return res;
}

int main()
{
    system("pause");
    return 0;
}