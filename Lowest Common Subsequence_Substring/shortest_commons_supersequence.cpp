#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

void init(int x, int y)
{
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int supersequence(string str1, string str2, int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    else if (str1[x - 1] == str2[y - 1])
    {
        return dp[x][y] = supersequence(str1, str2, x - 1, y - 1) + 1;
    }
    else
    {
        int option1 = supersequence(str1, str2, x - 1, y);
        int option2 = supersequence(str1, str2, x, y - 1);
        return dp[x][y] = max(option1, option2);
    }
}

int main()
{

    string str1, str2;
    cin >> str1 >> str2;
    int x = str1.size();
    int y = str2.size();
    init(x, y);
    int len_lcs = supersequence(str1, str2, x, y);
    cout<<(x+y)-len_lcs;
    return 0;
}