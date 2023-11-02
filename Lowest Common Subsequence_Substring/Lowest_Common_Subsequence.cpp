#include <bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2, int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    if (str1[x - 1] == str2[y - 1])
    {
        return LCS(str1, str2, x - 1, y - 1) + 1;
    }
    else
    {
        int option1 = LCS(str1, str2, x, y - 1);
        int option2 = LCS(str1, str2, x - 1, y);
        return max(option1, option2);
    }
}

int main()
{

    string str1, str2;
    cin >> str1 >> str2;
    int x = str1.size();
    int y = str2.size();
    cout << LCS(str1, str2, x, y) << "\n";

    return 0;
}