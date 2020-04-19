
// 2020/2/10 //

#include "0_linklist.h"

#include <vector>
#include <set>
#include <unordered_set>

using std::vector;
using std::set;
using std::unordered_set;

int numComponents1(ListNode* head, vector<int>& G)
{
    set<int> comp(G.begin(), G.end()); // set to compare
    bool flag = false; // breakage flag
    int res = 0; // result of sum component
    ListNode* curr = head; // traverse pointer
    while(curr)
    {
        set<int>::iterator iter = comp.find(curr->val); // search current value
        if(iter != comp.end()) // found
        {
            flag = true;
        }
        else // not found
        {
            if(flag == true) // exist component
            {
                res++; // number of component increase one
            }
            flag = false; // restore flag
        }
        curr = curr->next;
    }
    
    if(flag == true) // juege tail of list
    {
        res++;
    }
    return res;
}

int numComponent2(ListNode* head, vector<int>& G)
{
    unordered_set<int> comp(G.begin(), G.end()); // set to compare
    int len = 0; // temporary variable to record length of each component
    int res = 0; // result of sum component
    ListNode* curr = head; // traverse pointer
    while(curr)
    {
        if(comp.count(curr->val)) // found
        {
            len++; // length of component increase one
        }
        else // not found
        {
            len = 0; // restore length
        }
        
        if(len == 1) // record once when the length larger than zero
        {
            res++;
        }
        curr = curr->next;
    }

    return res;
}

int main()
{
    system("pause");
    return 0;
}