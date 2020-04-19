
// 2020/2/9 //

#include "0_linklist.h"

#include <set>
#include <algorithm>

using std::set;
using std::find;

bool hasCycle1(ListNode* head)
{
    set<ListNode*> visited; // set to store address
    ListNode* cur = head; // traverse pointer
    while(cur)
    {
        set<ListNode*>::iterator rst = visited.find(cur); // search result
        if(rst != visited.end()) // search successfully, exists loop
        {
            return true; // has loop
        }
        else // new address
        {
            visited.insert(cur); // add address
        }
        cur = cur->next;
    }
    
    return false; // has no loop
}

bool hasCycle2(ListNode* head)
{
    ListNode* fast = head; // fast pointer, two step each time
    ListNode* slow = head; // slow pointer, one step each time

    while(fast != nullptr && fast->next != nullptr)
    {
        if(slow->next == fast->next->next) // judge loop beforehand
        {
            return true; // has loop
        }
        slow = slow->next;
        fast = fast->next->next;
        if(fast == nullptr || slow == nullptr) // exist null pointer
        {
            return false; // has no loop
        }
    }

    return false;
}

int main()
{


    system("pause");
    return ;
}