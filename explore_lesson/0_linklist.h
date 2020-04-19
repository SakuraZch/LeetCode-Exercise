
// 2019/10/7 //

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getListLen(ListNode* list)
{
    int count = 0;
    ListNode* pCur = list;
    while(pCur != nullptr)
    {
        count++;
        pCur = pCur->next;
    }
    return count;
}

void addZeroToList(int numOfZero, ListNode* list)
{
    ListNode* pCur = list;
    while (pCur->next != nullptr)
        pCur = pCur->next;

    while(numOfZero--)
    {
        ListNode* newNode = new ListNode(0);
        pCur->next = newNode;
        pCur = newNode;
    }
}

void showList(ListNode* list)
{
    ListNode* pCur = list;
    while(pCur != nullptr)
    {
        cout << pCur->val << " ";
        pCur = pCur->next;
    }
    cout << endl;
    return ;
}

void destoryList(ListNode* list)
{
    int len = getListLen(list);
    ListNode* pCur = list;
    for(int i = 0; i < len; i++)
    {
        ListNode* temp = pCur;
        pCur = pCur->next;
        delete temp;
    }
    return ;
}