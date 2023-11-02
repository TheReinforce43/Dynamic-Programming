#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str1, str2;
    cin >> str1 >> str2;

    int x = str1.size();
    int y = str2.size();
    int dp[x + 1][y + 1];

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[x][y] << "\n";
    cout << "Result of LCS\n";
    vector<char> ans;

    while ((x != 0) && (y != 0))
    {

        if (str1[x - 1] == str2[y - 1])
        {
            ans.push_back(str1[x - 1]);
            x--;
            y--;
        }
        else if (str1[x - 1] != str2[y - 1])
        {
            int option1 = dp[x - 1][y];
            int option2 = dp[x][y - 1];
            if (option1 < option2)
            {
                y--;
            }
            else
            {
                x--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (char ch : ans)
        cout << ch;

    return 0;
}