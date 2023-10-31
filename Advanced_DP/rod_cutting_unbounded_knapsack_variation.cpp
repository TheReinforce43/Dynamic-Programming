#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

void init(int n, int s)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
            dp[i][j] = -1;
    }
}

int rod_cutting(int wt[], int val[], int n, int s)
{
    if (n == 0 || s == 0)
    {
        return 0;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    else if (wt[n - 1] <= s)
    {
        int option1 = rod_cutting(wt, val, n, s - wt[n - 1]) + val[n - 1];
        int option2 = rod_cutting(wt, val, n - 1, s);
        return dp[n][s] = max(option1, option2);
    }
    else
        return dp[n][s] = rod_cutting(wt, val, n - 1, s);
}

int main()
{

    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        wt[i] = i + 1;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    init(n, n);

    cout << rod_cutting(wt, val, n, n);

    return 0;
}