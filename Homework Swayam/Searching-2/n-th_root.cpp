#include<iostream>
using namespace std;
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
   //searcg space will be from 1 to m
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int ans = func(mid, n, m);
        if (ans == 1)
        {
            return mid;
        }
        else if (ans == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}