
#include "0_linklist.h"

void deleteNode1(ListNode* node)
{
    ListNode* temp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete temp;
}

void deleteNode2(ListNode* node)
{
    ListNode* temp = node->next;
    *(node) = *(node->next);
    delete temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    ListNode* head = createList(arr, sizeof(arr) / sizeof(int));

    ListNode* ptr = head->next;

    showList(head);
    deleteNode2(ptr);
    showList(head);

    system("pause");
    return 0;
}