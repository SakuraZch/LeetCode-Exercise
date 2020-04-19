
// 2020/2/16 //

#include "0_linklist.h"

ListNode* middleNode(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    system("pause");
    return 0;
}