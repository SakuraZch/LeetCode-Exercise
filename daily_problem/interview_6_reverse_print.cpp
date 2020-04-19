
// 2020/2/16 //

#include "0_linklist.h"

#include <vector>
#include <stack>

using std::vector;
using std::stack;

vector<int> reversePrint1(ListNode* head)
{   
    vector<int> vt;
        
    ListNode* curr = head;
    while(curr != nullptr)
    {
        vt.push_back(curr->val);
        curr = curr->next;
    }
    vector<int> reverseVt(int(vt.size()), 0);
    for(int i = int(vt.size()) - 1, j = 0; i >=0 && j < int(vt.size()); i--, j++)
    {
        reverseVt[j] = vt[i];
    }

    return reverseVt;
}

vector<int> reversePrint2(ListNode* head)
{
    vector<int> res;
    stack<int> tempStack;

    ListNode* curr = head;
    while(curr != nullptr)
    {
        tempStack.push(curr->val);
        curr = curr->next;
    }
    while(!tempStack.empty())
    {
        res.push_back(tempStack.top());
        tempStack.pop();
    }

    return res;
}

void recursivelyPush(ListNode* head, vector<int>& res)
{
    if(head)
    {
        if(head->next)
        {
            recursivelyPush(head->next, res);
        }
        res.push_back(head->val);
    }
}

vector<int> reversePrint3(ListNode* head)
{
    vector<int> res;
    recursivelyPush(head, res);
    return res;
}