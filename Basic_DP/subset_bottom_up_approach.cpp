#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;
    int arr[N + 1];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int s;
    cin >> s;
    bool dp[N + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
        dp[0][i] = false;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[N][s])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}