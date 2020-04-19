
// 2020/2/6 //

#include <vector>

#include "0_linklist.h"

using std::vector;

ListNode* partition(ListNode* head, int x)
{
    vector<int> lessVt;
    vector<int> biggerVt;

    ListNode* tempPtr = head;
    while(tempPtr)
    {
        if(tempPtr->val < x)
        {
            lessVt.push_back(tempPtr->val);
        }
        else
        {
            biggerVt.push_back(tempPtr->val);
        }
        tempPtr = tempPtr->next;
    }

    vector<int> totalVt;
    while(!biggerVt.empty())
    {
        totalVt.push_back(biggerVt.back());
        biggerVt.pop_back();
    }
    while(!lessVt.empty())
    {
        totalVt.push_back(lessVt.back());
        lessVt.pop_back();
    }

    tempPtr = head;
    while(tempPtr)
    {
        tempPtr->val = totalVt.back();
        totalVt.pop_back();
        tempPtr = tempPtr->next;
    }

    return head;
}

int main()
{


    system("pause");
    return 0;
}