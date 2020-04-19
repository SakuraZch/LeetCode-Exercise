
#include <iostream>
#include <cstdlib>

int F1(int N = 0)
{
    if(N == 0)
    {
        return 1;
    }
    else
    {
        return N * F1(N - 1);
    }
}

int F2(int N = 0)
{
    if(N == 0)
    {
        return 0;
    }
    else
    {
        return N + F2(N - 1);
    }
}

int F3(int N = 0)
{
    if(N == 0)
    {
        return 0;
    }
    else if(N == 1)
    {
        return 1;
    }
    else
    {
        return F3(N - 1) + F3(N - 2);
    }
    
}

int F4(int N = 0, int K = 0)
{
    if(N == 0 || N == K || K == 0)
    {
        return 1;
    }
    else
    {
        return F4(N - 1, K - 1) + F4(N - 1, K);
    }
}

int main()
{
    std::cout << F1(5) << std::endl;
    std::cout << F2(5) << std::endl;
    std::cout << F3(11) << std::endl;
    std::cout << F4(6, 3) << std::endl;

    system("pause");
    return 0;
}