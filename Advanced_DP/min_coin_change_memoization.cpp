#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int dp[1005][1005];
void init(int n, int s)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
            dp[i][j] = -1;
    }
}
int min_coin(int arr[], int n, int s)
{
    if (n == 0)
    {
        if (s == 0)
            return 0;
        else
            return inf;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    else if (arr[n - 1] <= s)
    {
        int option1 = min_coin(arr, n, s - arr[n - 1]) + 1;
        int option2 = min_coin(arr, n - 1, s);
        dp[n][s] = min(option1, option2);
        return dp[n][s];
    }
    else
        return dp[n][s] = min_coin(arr, n - 1, s);
}

int main()
{

    int n, s;
    cin >> n >> s;
    int arr[n];
    init(n, s);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << min_coin(arr, n, s);

    return 0;
}