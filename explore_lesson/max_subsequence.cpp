
// 2020/3/7 //

#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void MaxSubsequence1(int len, const vector<int>& intArr)
{
    int maxVal = 0, startInd = 0, endInd = 0;

    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            int tempMaxVal = 0;
            for(int k = i; k <= j; k++)
            {
                tempMaxVal += intArr[k];
                if(tempMaxVal > maxVal)
                {
                    maxVal = tempMaxVal;
                    startInd = i;
                    endInd = j;
                }
            }
        }
    }

    cout << maxVal << " " << startInd << " " << endInd << endl;
}

void MaxSubsequence2(int len, const vector<int>& intArr)
{
    bool tag = false;
    for(int i = 0; i < len; i++)
    {
        if(intArr[i] >= 0)
        {
            tag = true;
        }
    }
    if(tag == false)
    {
        cout << "0 " << intArr[0] << " " << intArr[len - 1] << endl;
        return ;
    }

    int thisSum = 0;
	int maxSum = 0;
    int sumNum = 0;
    int startInd = 0, endInd = 0;
	
	for(int i = 0; i < len; i++)
    {
		thisSum += intArr[i];
        
		if(thisSum > maxSum)
        {
			maxSum = thisSum;
            endInd = i;
		}
        else if(thisSum == maxSum)
        {
            sumNum++;
        }
		else if(thisSum < 0)
        {
            thisSum = 0;
        }
	}

    int tempSum = 0;
    for(int i = endInd; i >= 0; i--)
    {
        tempSum += intArr[i];
        if(tempSum == maxSum)
        {
            while(intArr[i - 1] == 0)
            {
                i--;
            }
            startInd = i;
            break;
        }
    }

    cout << sumNum << endl;
    if(sumNum > 1)
    {
        cout << maxSum << " " << startInd << " " << endInd << endl;
    }
	else
    {
        cout << maxSum << " " << intArr[startInd] << " " << intArr[endInd] << endl;
    }
}

int main()
{
    MaxSubsequence2(12, {-10, 0, 0, -1, -2, -3, -5, -5, -23, -3, -7, -21});

    system("pause");
    return 0;
}
