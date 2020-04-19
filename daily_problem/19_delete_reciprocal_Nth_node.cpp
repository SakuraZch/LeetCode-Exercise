
// 2019/10/7 //

#include "0_linklist.h"

bool removeNthNode(ListNode** list, int pos, int* value)
{
    int len = getListLen(*list);
    if(pos < 1 || pos > len)
    {
        cout << "Position out of range!" << endl;
        return false;
    }

    if(pos == 1)
    {
        ListNode* temp = *list;
        *list = (*list)->next;
        temp->next = nullptr;
        delete temp;
        return true;
    }
    else if(pos == len)
    {
        ListNode* pCur = *list;
        while(pCur->next->next != nullptr)
            pCur = pCur->next;
        ListNode* temp = pCur->next;
        pCur->next = nullptr;
        delete temp;
        return true;
    }
    else
    {
        ListNode* pCur = *list;
        int idx = 0;
        while(idx < pos - 2)
        {
            pCur = pCur->next;
            idx++;
        }
        ListNode* temp = pCur->next;
        *value = temp->val;
        pCur->next = pCur->next->next;
        delete temp;
        return true;
    }
}

ListNode* removeNthFromEnd1(ListNode* list, int posRev)
{
    if(posRev == 1 && getListLen(list) == 1)
        return nullptr;
    int len = getListLen(list);
    int pos = len - posRev + 1;
    int tempVal = 0;
    removeNthNode(&list, pos, &tempVal);
    return list;
}

ListNode* removeNthFromEnd2(ListNode* list, int posRev)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = list;
    ListNode* ptr1 = dummyHead;
    ListNode* ptr2 = dummyHead;

    posRev++;

    while(posRev--)
        ptr1 = ptr1->next;
    
    while(ptr1 != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    ListNode* temp = ptr2->next;
    ptr2->next = temp->next;
    delete temp;

    ListNode* newList = dummyHead->next;
    delete dummyHead;

    return newList;
}

int main()
{
    ListNode* l11 = new ListNode(1);
    ListNode* l12 = new ListNode(2);
    ListNode* l13 = new ListNode(3);
    ListNode* l14 = new ListNode(2);
    l11->next = l12;
    l12->next = l13;
    l13->next = l14;

    int tempVal = 0;

    l11 = removeNthFromEnd1(l11, 1);
    showList(l11);
    l11 = removeNthFromEnd2(l11, 2);
    showList(l11);

    destoryList(l11);


    system("pause");
    return 0;
}

