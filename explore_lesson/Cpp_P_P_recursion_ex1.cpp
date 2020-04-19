
// 2019/12/2 //

#include <iostream>

using namespace std;

void countdown(int n);

int main()
{
    countdown(4);

    system("pause");
    return 0;
}

// 递归：触底反弹
void countdown(int n) 
{
    cout << "Counting down ..." << n << endl; // 部分1：前驱
    if(n > 0)
        countdown(n - 1); // 部分2：断点
    cout << n << ": Kaboom!" << endl; // 部分3：后继
}

// ---
// |4
// ---
//  <-|3
//    ---
//     <-|2
//       ---
//        <-|1
//          ---
//      反弹 <-|0 触底
//             ---








