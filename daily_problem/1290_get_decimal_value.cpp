
// 2020/2/9 //

#include "0_linklist.h"

#include <cmath>

using std::pow;

int getDecimalValue1(ListNode* head)
{
    int res = 0;
    int len = getListLen(head); // get the length of list
    ListNode* cur = head; // traverse pointer
    for(int i = len - 1; i >= 0; i--)
    {
        res += pow(2, i) * cur->val; // get sum
        cur = cur->next; // step forward
    }

    return res;
}

int getDecimalValue2(ListNode* head)
{
    int res = 0;
    ListNode* cur = head;
    while(cur)
    {
        res = res * 2 + cur->val;
        cur = cur->next;
    }

    return res;
}

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    ListNode* hd = createList(arr, sizeof(arr) / sizeof(int));
    
    int num = getDecimalValue2(hd);

    cout << num << endl;

    showList(hd);

    destoryList(hd);

    system("pause");
    return 0;
}


