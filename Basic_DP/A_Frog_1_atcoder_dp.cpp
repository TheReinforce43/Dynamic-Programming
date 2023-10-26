#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
int dp[N];
void init(int len)
{
    for (int i = 0; i <= len; i++)
    {
        dp[i] = -1;
    }
}

int solution(int arr[], int len)
{
    if (len == 1)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    else if (len == 2)
    {
        return dp[len] = abs(arr[len] - arr[len - 1]);
    }
    else
    {
        int choice1 = solution(arr, len - 1) + abs(arr[len] - arr[len - 1]);
        int choice2 = solution(arr, len - 2) + abs(arr[len] - arr[len - 2]);
        return dp[len] = min(choice1, choice2);
    }
}

int main()
{
    int len;
    cin >> len;
    init(len);

    int arr[len + 1];
    for (int i = 1; i <= len; i++)
    {
        cin >> arr[i];
    }
    cout << solution(arr, len) << "\n";

    return 0;
}