#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (int j = 1; j <= s; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (arr[i - 1] <= j)
            {
                int option1 = dp[i - 1][j - arr[i - 1]];
                int option2 = dp[i - 1][j];
                dp[i][j] = option1 + option2;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][s] << "\n";

    return 0;
}