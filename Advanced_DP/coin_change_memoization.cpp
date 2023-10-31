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

int coin_change(int wt[], int n, int s)
{
    if (n == 0)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    else if (wt[n - 1] <= s)
    {
        int option1 = coin_change(wt, n, s - wt[n - 1]);
        int option2 = coin_change(wt, n - 1, s);
        return dp[n][s] = option1 + option2;
    }
    else
        return dp[n][s] = coin_change(wt, n - 1, s);
}

int main()
{

    int n, target;
    cin >> n >> target;
    init(n, target);
    int wt[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << coin_change(wt, n, target) << "\n";
    // cout<<dp[n][target]<<" ";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}