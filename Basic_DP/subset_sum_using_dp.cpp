#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[], int n, int target)
{
    if (n == 0)
    {
        return target == 0 ? true : false;
    }
    else if (arr[n - 1] <= target)
    {
        bool option1 = subset_sum(arr, n - 1, target - arr[n - 1]);
        bool option2 = subset_sum(arr, n - 1, target);
        return option1 || option2;
    }
    else
        return subset_sum(arr, n - 1, target);
}

int main()
{
    int N;
    cin >> N;
    int nums[N + 1];
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    int target;
    cin >> target;
    if (subset_sum(nums, N, target))
    {
        cout << "Subset is detected\n";
    }
    else
        cout << "Subset is not detected\n";

    return 0;
}