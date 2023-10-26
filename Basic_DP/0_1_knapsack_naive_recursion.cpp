#include <bits/stdc++.h>
using namespace std;

int knapsack(int value[], int weight[], int N, int target)
{
    if (target == 0 || N == 0)
        return 0;
    if (weight[N - 1] <= target)
    {
        int option1 = knapsack(value, weight, N - 1, target - weight[N - 1]) + value[N - 1];
        int option2 = knapsack(value, weight, N - 1, target);
        return max(option1, option2);
    }
    else
    {
        return knapsack(value, weight, N - 1, target);
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
    cout << knapsack(value, weight, N, target);
    return 0;
}