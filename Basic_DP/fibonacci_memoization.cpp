#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
long long int series[N];
void init(int len)
{
    for (int i = 0; i <= len; i++)
    {
        series[i] = -1;
    }
}

long long int fibo(int len)
{
    if (len <= 1)
        return 1;
    if (series[len] != -1)
    {
        return series[len];
    }
    series[len] = fibo(len - 1) + fibo(len - 2);
    return series[len];
}

int main()
{
    int len;
    cin >> len;
    init(len);

    cout << fibo(len);

    return 0;
}