
// 2020/2/6 //

#include "0_linklist.h"

ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    if(headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }

    ListNode* pA = headA;
    ListNode* pB = headB;
    while(pA != pB)
    {
        pA = (pA == nullptr) ? headB : pA->next;
        pB = (pB == nullptr) ? headA : pB->next;
    }

    return pA;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    if(headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }

    while(headA)
    {
        ListNode *pt = headB;
        while(pt)
        {
            if(headA == pt)
            {
                return pt;
            }
            pt = pt->next;
        }
        headA = headA->next;
    }
    
    return headA;
}

int main()
{

    system("pause");
    return 0;
}