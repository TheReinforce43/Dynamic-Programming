#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

void init(int n, int s)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
            dp[i][j] = -1;
    }
}

int subset_sum(int value[], int n, int s)
{
    if (n == 0)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }
    if (dp[n][s] != -1)
        return 1;
    else if (value[n - 1] <= s)
    {
        int option1 = subset_sum(value, n - 1, s - value[n - 1]);
        int option2 = subset_sum(value, n - 1, s);
        return dp[n][s] = option1 + option2;
    }
    else
        return dp[n][s] = subset_sum(value, n - 1, s);
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int s;
    cin >> s;
    init(n, s);
    cout << subset_sum(arr, n, s) << "\n";

    return 0;
}