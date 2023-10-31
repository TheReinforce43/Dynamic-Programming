#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        wt[i] = i + 1;
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                int option1 = dp[i][j - wt[i - 1]] + val[i - 1];
                int option2 = dp[i - 1][j];
                dp[i][j] = max(option1, option2);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][n] << "\n";

    return 0;
}