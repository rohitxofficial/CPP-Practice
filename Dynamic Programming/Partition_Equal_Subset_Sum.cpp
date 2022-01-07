#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
bool canPartitionHelper(int n, int *nums, int sum, int **dp)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool x = canPartitionHelper(n - 1, nums, sum, dp);

    bool y = false;

    if (x != true && sum - nums[n - 1] >= 0)
        y = canPartitionHelper(n - 1, nums, sum - nums[n - 1], dp);

    dp[n][sum] = (x || y);

    return (x || y);
}

bool canPartition(int n, int *nums)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    if (sum % 2 != 0)
        return false;

    int **dp = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sum / 2 + 1];
        for (int j = 0; j <= (sum / 2); j++)
        {
            dp[i][j] = -1;
        }
    }

    return canPartitionHelper(n, nums, sum / 2, dp);
}

// DYNAMIC PROGRAMMING
bool canPartitionDP(int n, int *nums)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    if (sum % 2 != 0)
        return false;

    sum = sum / 2;

    bool **dp = new bool *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = new bool[sum + 1];
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = 0;

            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool x = dp[i - 1][j];

            bool y = false;

            if (x != true && j - nums[i - 1] >= 0)
                y = dp[i - 1][j - nums[i - 1]];

            dp[i][j] = (x || y);
        }
    }

    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (canPartitionDP(n, arr))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}