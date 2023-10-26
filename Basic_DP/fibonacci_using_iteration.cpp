#include <bits/stdc++.h>
using namespace std;

long long int fibo(int len)
{
    long long int ans[len+1];
    ans[0] = 1;
    ans[1] = 1;

    for (int i = 2; i <= len; i++)
    {
        ans[i] =ans[i - 1]+ ans[i - 2] ;
    }
    return ans[len];
}

int main()
{
    int len;
    cin>>len;
    cout << fibo(len);

    return 0;
}