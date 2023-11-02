#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str1, str2;
    cin >> str1 >> str2;
    int x = str1.size();
    int y = str1.size();

    int dp[x + 1][y + 1];

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j]=0;
                continue;
            }
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                int option1 = dp[i][j - 1];
                int option2 = dp[i - 1][j];
                dp[i][j] = max(option1, option2);
            }
        }
        //cout<<"ha ha\n";
    }
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    //cout << dp[x][y] << "\n";

    return 0;
}