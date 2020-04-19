
// 2020/2/7 //

#include "0_linklist.h"

ListNode* reverseList1(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* prev = nullptr; // previous pointer
    ListNode* curr = head; // current pointer
    while(curr != nullptr)
    {
        ListNode* temp = curr->next; // store the next pointer
        curr->next = prev; // reverse
        // renew
        prev = curr;
        curr = temp;
    }
    
    return prev; // pointer "prev" is the new head
}

ListNode* reverseList2(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // pointer "ptr" is the new head of list
    ListNode* ptr = reverseList2(head->next);
    head->next->next = head; // reverse
    head->next = nullptr; // set null
    return ptr;
}

int main()
{

    system("pause");
    return 0;
}