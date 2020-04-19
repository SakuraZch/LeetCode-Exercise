
// 2020/2/13 //

#include "0_linklist.h"

ListNode* merge1(ListNode* node1, ListNode* node2)
{
    if(node1 == nullptr)
    {
        return node2;
    }
    if(node2 == nullptr)
    {
        return node1;
    }

    if(node1->val <= node2->val)
    {
        node1->next = merge1(node1->next, node2);
        return node1;
    }
    else
    {
        node2->next = merge1(node2->next, node1);
        return node2;
    }
}

// ? recursion version
ListNode* sortList1(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* left = head;
    ListNode* middle = head;
    ListNode* right = head;
    while(right != nullptr && right->next != nullptr)
    {
        middle = left;
        left = left->next;
        right = right->next->next;
    }
    middle->next = nullptr;

    return merge1(sortList1(head), sortList1(left));
}

ListNode* cut(ListNode* head, int n)
{
    ListNode* ptr = head;
    // using "--n" to get the previous node of the new head of list
    while(--n && ptr != nullptr)
    {
        ptr = ptr->next;
    }

    if(ptr == nullptr) // check "n" is longer than length of list
    {
        return nullptr;
    }

    ListNode* newHead = ptr->next; // temporary store
    ptr->next = nullptr; // cut
    return newHead;
}

ListNode* merge(ListNode* node1, ListNode* node2)
{
    ListNode dummyHead(0);
    ListNode* ptr = &dummyHead;
    while(node1 != nullptr && node2 != nullptr) // merge two lists
    {
        // confirm the less one
        if(node1->val <= node2->val)
        {
            ptr->next = node1;
            ptr = node1;
            node1 = node1->next;
        }
        else
        {
            ptr->next = node2;
            ptr = node2;
            node2 = node2->next;
        }
    }
    ptr->next = (node1 != nullptr) ? node1 : node2; // link least part

    return dummyHead.next;
}

ListNode* sortList(ListNode* head)
{
    ListNode dummyHead(0);
    dummyHead.next = head;
    int length = getListLen(head); // get the length of list

    for(int size = 1; size < length; size <<= 1) // confirm the length of sorting
    {
        ListNode* curr = dummyHead.next;
        ListNode* tail = &dummyHead;
        while(curr != nullptr)
        {
            ListNode* left = curr;
            ListNode* right = cut(left, size);
            curr = cut(right, size);

            tail->next = merge(left, right); 
            while(tail->next != nullptr)
            {
                tail = tail->next;
            }
        }
    }

    return dummyHead.next;
}