#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
bool subsetSum(int n, int *arr, int sum, int **dp)
{
    if (sum == 0)
        return 1;

    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool x = subsetSum(n - 1, arr + 1, sum, dp);

    bool y = false;

    if (sum - arr[0] >= 0)
        y = subsetSum(n - 1, arr + 1, sum - arr[0], dp);

    dp[n][sum] = x || y;

    return dp[n][sum];
}

bool subsetSumHelper(int n, int *arr, int sum)
{
    int **dp = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sum + 1];
        for (int j = 0; j <= sum; j++)
            dp[i][j] = -1;
    }

    return subsetSum(n, arr, sum, dp);
}

// DYNAMIC PROGRAMMING
bool subsetSumDP(int n, int *arr, int sum)
{
    bool **dp = new bool *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = new bool[sum + 1];
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool x = dp[i - 1][j];

            bool y = false;

            if (j - arr[i - 1] >= 0)
                y = dp[i - 1][j - arr[i - 1]];

            dp[i][j] = x || y;
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

    int sum;
    cin >> sum;

    if (subsetSumDP(n, arr, sum))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}