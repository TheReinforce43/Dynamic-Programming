#include <bits/stdc++.h>
using namespace std;
const int N = 1450;
int dp[N][N];

void init(int N, int S)
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            dp[i][j] = -1;
        }
    }
}

int knapsack(int value[], int weight[], int len, int target)
{
    if (len == 0 || target == 0)
        return 0;
    if (dp[len][target] != -1)
    {
        return dp[len][target];
    }
    else if (weight[len - 1] <= target)
    {
        int option1 = knapsack(value, weight, len - 1, target - weight[len - 1]) + value[len - 1];
        int option2 = knapsack(value, weight, len - 1, target);
        return dp[len][target] = max(option1, option2);
    }
    else
    {
        return dp[len][target] = knapsack(value, weight, len - 1, target);
    }
}

int main()
{

    int len;
    cin >> len;
    int value[len + 1], weight[len + 1];

    for (int i = 1; i <= len; i++)
    {
        cin >> value[i];
    }

    for (int i = 1; i <= len; i++)
    {
        cin >> weight[i];
    }
    int target;
    cin >> target;
    init(len, target);
    cout << knapsack(value, weight, len, target);

    return 0;
}