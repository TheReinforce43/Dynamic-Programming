#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int solve(int save[], int len)
{
    if (len == 1)
        return 0;
    else if (len == 2)
    {
        return abs(save[2] - save[1]);
    }
    else
    {
        int choice1 = solve(save, len - 1) + abs(save[len] - save[len - 1]);
        int choice2 = solve(save, len - 2) + abs(save[len] - save[len - 2]);
        return min(choice1, choice2);
    }
}

int main()
{
    int len;
    cin >> len;
    int save[len + 1];

    for (int i = 1; i <= len; i++)
    {
        cin >> save[i];
    }
    cout << solve(save, len);

    return 0;
}