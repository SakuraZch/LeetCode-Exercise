
// 2020/2/12 //

#include "0_linklist.h"

#include <ctime>
#include <chrono>

using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::clock_t;
using std::clock;

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == nullptr)
    {
        return head;
    }

    int len = getListLen(head); // get length of list

    k = k % len; // make "k" less than "len"
    if(k == 0) return head;
    
    ListNode* newHd = head;
    ListNode* newTl = head;
    while(newTl->next) // reach list tail
    {
        newTl = newTl->next;
    }
    newTl->next = newHd; // construct loop

    newTl = newHd; // prepare traverse
    for(int i = 0; i < len - k - 1; i++) // search new tail
    {
        newTl = newTl->next;
    }
    newHd = newTl->next; // new head is the next node of new tail
    newTl->next = nullptr; // break loop

    return newHd;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, sizeof(arr) / sizeof(int));
    int tst;
    showList(head);

    auto start = system_clock::now();
    head = rotateRight(head, 3);
    for(int i = 0; i < 1000000; i++);
    auto finish = system_clock::now();

    showList(head);
    auto duration = duration_cast<microseconds>(finish - start);
 
    cout << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;

    system("pause");
    return 0;
}