
// 2019/10/7 //

#include "0_linklist.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int len1 = getListLen(l1);
    int len2 = getListLen(l2);
    
    if(len1 > len2)
        addZeroToList(len1 - len2, l2);
    else if(len1 < len2)
        addZeroToList(len2 - len1, l1);
    int len = len1 >= len2 ? len1 : len2;

    ListNode* pCur1 = l1, * pCur2 = l2;
    for(int i = 0; i < len; i++)
    {
        int bitSum = pCur1->val + pCur2->val;
        if(bitSum < 10)
            pCur1->val += pCur2->val;
        else
        {
            pCur1->val = bitSum % 10;
            if(pCur1->next != nullptr)
                pCur1->next->val += 1;
            else
            {
                ListNode* newNode = new ListNode(1);
                pCur1->next = newNode;
            }
        }
        pCur1 = pCur1->next;
        pCur2 = pCur2->next;
    }
    return l1;
}

int main()
{
    ListNode* l11 = new ListNode(9);
    ListNode* l12 = new ListNode(8);
    //ListNode* l13 = new ListNode(3);
    //ListNode* l14 = new ListNode(9);

    ListNode* l21 = new ListNode(1);
    //ListNode* l22 = new ListNode(1);
    //ListNode* l23 = new ListNode(8);
    // ListNode* l24 = new ListNode(8);

    l11->next = l12;
    //l12->next = l13;
    //l13->next = l14;

    //l21->next = l22;
    //l22->next = l23;
    // l23->next = l24;
    
    int len1 = getListLen(l11);

    showList(l11);
    showList(l21);

    ListNode* sum = addTwoNumbers(l11, l21);
    showList(l11);

    destoryList(l11);
    destoryList(l21);

    system("pause");
    return 0;
}