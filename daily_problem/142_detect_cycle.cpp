
// 2020/2/9 //

#include "0_linklist.h"

#include <set>

using std::set;

ListNode* detectCycle(ListNode* head)
{
    set<ListNode*> visited;
    ListNode* ptr = head;
    while(ptr)
    {
        set<ListNode*>::iterator rst = visited.find(ptr);
        if(rst != visited.end())
        {
            return *rst;
        }
        else
        {
            visited.insert(ptr);
        }
        ptr = ptr->next;
    }
    
    return nullptr;
}

int main()
{
    system("pause");
    return 0;
}