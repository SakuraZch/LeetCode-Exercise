
// 2020/2/7 //

#include "0_linklist.h"

ListNode* reverseList(ListNode* head)
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

void reorderList(ListNode* head)
{
    if(head == nullptr) // null head pointer
    {
        return ; // return directly
    }

    ListNode* sential = new ListNode(-1);
    sential->next = head;

    ListNode* fast = head; // fast pointer
    ListNode* slow = head; // slow pointer
    // take list apart
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next; // one step each time
        fast = fast->next->next; // two step each time
    }
    
    ListNode* left = head; // left sub-list
    ListNode* right = slow->next; // right sub-list
    slow->next = nullptr; // assign the pointer at the tail of the left list null
    right = reverseList(right); // reverse right list
    ListNode* temp = sential; // store initial sential node
    while(left || right) // relink two sub-list
    {
        if(left) // pointer of left list is not null
        {
            sential->next = left; // link
            // advance
            left = left->next;
            sential = sential->next;
        }

        if(right) // pointer of right list is not null
        {
            sential->next = right; // link
            // advance
            right = right->next;
            sential = sential->next;
        }
    }

    delete temp; // release memory of the initial sential node
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* hd = createList(arr, sizeof(arr) / sizeof(int));
    
    reorderList(hd);

    showList(hd);

    destoryList(hd);

    system("pause");
    return 0;
}
        