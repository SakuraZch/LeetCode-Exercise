
#include <cmath>
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int transformD2B(int dec)
{
    int result = 0, temp = dec, j = 1;
    while(temp){
        result = result + j * (temp % 2);
        temp = temp / 2;
        j = j * 10;
    }
    return result;
}

int main()
{
    int num;
    cin >> num;
    num = transformD2B(num);
    cout << num << endl;

    system("pause");
    return 0;
}