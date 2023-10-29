#include <bits/stdc++.h>
using namespace std;

int dp[101][1001]; // Assuming constraints for N and target

int knapsack(int value[], int weight[], int N, int target)
{
    if (target == 0 || N == 0)
        return 0;

    if (dp[N][target] != -1)
    {
        return dp[N][target];
    }

    else if (weight[N - 1] <= target)
    {
        int option1 = knapsack(value, weight, N - 1, target - weight[N - 1]) + value[N - 1];
        int option2 = knapsack(value, weight, N - 1, target);
        return dp[N][target] = max(option1, option2);
    }
    else
    {
        return dp[N][target] = knapsack(value, weight, N - 1, target);
    }
}

int main()
{
    int N;
    cin >> N;
    int weight[N + 1], value[N + 1];

    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i];
    }

    int target;
    cin >> target;

    // Initialize the dp array
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(value, weight, N, target);

    return 0;
}
