#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

void init(int len, int target)
{
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= target; j++)
            dp[i][j] = -1;
    }
}

bool SubsetSum(int arr[], int n, int target)
{
    if (n == 0)
    {
        if (target == 0)
            return true;
        else
            return false;
    }
    if (dp[n][target] != -1)
        return dp[n][target];
    else if (arr[n - 1] <= target)
    {
        bool option1 = SubsetSum(arr, n - 1, target - arr[n - 1]);
        bool option2 = SubsetSum(arr, n - 1, target);
        return dp[n][target] = option1 || option2;
    }
    else
        return dp[n][target] = SubsetSum(arr, n - 1, target);
}

int main()
{
    int N;
    cin >> N;
    int arr[N + 1];

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    init(N, target);
    if (SubsetSum(arr, N, target))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}