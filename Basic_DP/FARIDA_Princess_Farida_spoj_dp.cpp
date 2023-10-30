#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll monster(vector<ll> nums, vector<ll> &dp, int i, int n)
{
    if (i > n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll ans1 = monster(nums, dp, i + 2, n);
    ll ans2 = monster(nums, dp, i + 3, n);
    return dp[i] = nums[i] + max(ans1, ans2);
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int N;
        cin >> N;
        vector<ll> nums(N);
        for (int i = 0; i < N; i++)
            cin >> nums[i];
        vector<ll> dp(nums.size(), -1);
        ll ans1 = monster(nums, dp, 0, N - 1);
        ll ans2 = monster(nums, dp, 1, N - 1);
        // cout << max(ans1, ans2) << "\n";
        cout << "Case " << i << ": " << max(ans1, ans2) << "\n";
    }

    return 0;
}