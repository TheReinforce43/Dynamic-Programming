#include <bits/stdc++.h>
using namespace std;

int main()
{

    string A, B;
    cin >> A >> B;
    int x = A.size();
    int y = B.size();
    int dp[x + 1][y + 1];

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = 0;
        }
    }
    int mx = INT_MIN;
    int t_i, t_j;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (mx < dp[i][j])
            {
                mx = dp[i][j];
                t_i = i;
                t_j = j;
            }
        }
    }
    // cout<<mx;
    vector<char> ans;

    while ((t_i != 0) && (t_j != 0))
    {
        if (A[t_i - 1] == B[t_j - 1])
        {
            ans.push_back(A[t_i - 1]);
            t_i--;
            t_j--;
        }
        else
            break;
    }
    reverse(ans.begin(), ans.end());
    for (char ch : ans)
        cout << ch;
    return 0;
}