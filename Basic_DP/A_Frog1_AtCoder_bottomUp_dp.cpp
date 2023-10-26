#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cost[N + 1], dp[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);

    for (int i = 3; i <= N; i++)
    {
        int choice1 = dp[i-1] + abs(cost[i] - cost[i - 1]);
        int choice2 = dp[i-2] + abs(cost[i] - cost[i - 2]);
        dp[i] = min(choice1, choice2);
    }
    cout << dp[N] << "\n";

    return 0;
}