#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int findMax(int n, int *values, int *weights, int W, int **arr)
{
    if (n == 0 || W == 0)
        return 0;

    if (arr[n][W] != -1)
        return arr[n][W];

    int x = findMax(n - 1, values + 1, weights + 1, W, arr);

    int y = INT_MIN;

    if (W - weights[0] >= 0)
        y = values[0] + findMax(n - 1, values + 1, weights + 1, W - weights[0], arr);

    arr[n][W] = max(x, y);

    return arr[n][W];
}

int findMaxHelper(int n, int *values, int *weights, int W)
{
    int **arr = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[W + 1];
        for (int j = 0; j <= W; j++)
            arr[i][j] = -1;
    }

    return findMax(n, values, weights, W, arr);
}

// TOP DOWN
int findMaxDP(int n, int *values, int *weights, int W)
{
    int **arr = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[W + 1];
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int x = arr[i - 1][j];
            int y = INT_MIN;

            if (j - weights[i - 1] >= 0)
                y = values[i - 1] + arr[i - 1][j - weights[i - 1]];

            arr[i][j] = max(x, y);
        }
    }

    return arr[n][W];
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int *values = new int[n];
    for (int i = 0; i < n; i++)
        cin >> values[i];

    int W;
    cin >> W;

    cout << findMaxDP(n, values, weights, W) << endl;

    return 0;
}