
// 2020/2/7 //

#include "0_linklist.h"

ListNode* removeElements(ListNode* head, int val)
{
    ListNode* sential = new ListNode(-1); // sential node
    sential->next = head; // ahead of head node
    
    ListNode* prev = sential; // previous node
    ListNode* curr = head; // current node
    ListNode* toDel = nullptr; // node to delete
    while(curr) // traverse list
    {
        if(curr->val == val) // find successfully
        {
            prev->next = curr->next; // relink
            toDel = curr;
        }
        else // find failed
        {
            prev = curr; // move
        }

        curr = curr->next;

        if(toDel) // release memory
        {
            delete toDel;
            toDel = nullptr;
        }
    }

    ListNode* ret = sential->next;
    delete sential;
    return ret; // return new head
}

int main()
{

    system("pause");
    return 0;
}