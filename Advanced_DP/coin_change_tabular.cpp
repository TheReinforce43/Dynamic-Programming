#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, s;
    cin >> n >> s;
    int wt[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    int dp[n + 1][s + 1];

    dp[0][0] = 1;

    for (int i = 1; i <= s; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - wt[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][s] << "\n";

    return 0;
}