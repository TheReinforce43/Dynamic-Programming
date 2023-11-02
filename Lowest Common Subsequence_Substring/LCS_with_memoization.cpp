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

int lcs_memoization(string A, string B, int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    else if (A[x - 1] == B[y - 1])
    {
        return dp[x][y] = lcs_memoization(A, B, x - 1, y - 1) + 1;
    }
    else
    {
        int option1 = lcs_memoization(A, B, x - 1, y);
        int option2 = lcs_memoization(A, B, x, y - 1);
        return dp[x][y] = max(option1, option2);
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int x = str1.size();
    int y = str2.size();
    init(x,y);
    cout << lcs_memoization(str1, str2, x, y);

    return 0;
}