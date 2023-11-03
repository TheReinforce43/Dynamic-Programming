#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

void init(int x, int y)
{
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
            dp[i][j] = -1;
    }
}

string lcs_supersequence(string A, string B)
{
    int x = A.size();
    int y = B.size();
    string ans;
    while ((x != 0) && (y != 0))
    {
        if (A[x - 1] == B[y - 1])
        {
            ans += A[x - 1];
            x--;
            y--;
        }
        else if (dp[x - 1][y] > dp[x][y - 1])
        {
            ans += A[x - 1];
            x--;
        }
        else
        {
            ans += B[y - 1];
            y--;
        }
    }
    while (x)
    {
        ans += A[x - 1];
        x--;
    }
    while (y)
    {
        ans += B[y - 1];
        y--;
    }
    return ans;
}

int main()
{

    string A, B;
    cin >> A >> B;
    int x = A.size();
    int y = B.size();
    init(x, y);

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
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans=lcs_supersequence(A, B);
    reverse(ans.begin(),ans.end());
    for(char ch:ans) cout<<ch;

    return 0;
}