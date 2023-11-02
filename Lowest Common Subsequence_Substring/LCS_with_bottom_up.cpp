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

int lcs_bottom_up(string A, string B, int indx_A, int indx_B, int len_A, int Len_B)
{
    if (indx_A >= len_A || indx_B >= Len_B)
    {
        return 0;
    }
    if (dp[indx_A][indx_B] != -1)
        return dp[indx_A][indx_B];
    else if (A[indx_A] == B[indx_B])
    {
        return dp[indx_A][indx_B] = lcs_bottom_up(A, B, indx_A + 1, indx_B + 1, len_A, Len_B)+1;
    }
    else
    {
        int option1 = lcs_bottom_up(A, B, indx_A + 1, indx_B, len_A, Len_B);
        int option2 = lcs_bottom_up(A, B, indx_A, indx_B + 1, len_A, Len_B);
        return dp[indx_A][indx_B] = max(option1, option2);
    }
}

int main()
{

    string str1, str2;
    cin >> str1 >> str2;
    int x = str1.size();
    int y = str2.size();
    init(x, y);
    cout << lcs_bottom_up(str1, str2, 0, 0, x, y);
    return 0;
}