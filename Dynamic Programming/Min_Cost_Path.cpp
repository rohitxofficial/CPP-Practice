#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int minCostPath(int curr_r, int curr_c, int **arr, int r, int c, int **memo)
{
    if (curr_r == r && curr_c == c)
        return arr[r][c];

    if (memo[curr_r][curr_c] != -1)
    {
        return memo[curr_r][curr_c];
    }

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;

    if (curr_r + 1 <= r)
    {
        x = minCostPath(curr_r + 1, curr_c, arr, r, c, memo);
    }

    if (curr_c + 1 <= c)
    {
        y = minCostPath(curr_r, curr_c + 1, arr, r, c, memo);
    }

    if (curr_c + 1 <= c && curr_r + 1 <= r)
    {
        z = minCostPath(curr_r + 1, curr_c + 1, arr, r, c, memo);
    }

    int ans = arr[curr_r][curr_c] + min(x, min(y, z));

    memo[curr_r][curr_c] = ans;

    return ans;
}

int minCostPathHelper(int **arr, int r, int c)
{
    int **memo = new int *[r + 1];
    for (int i = 0; i <= r; i++)
    {
        memo[i] = new int[c + 1];
        for (int j = 0; j <= c; j++)
        {
            memo[i][j] = -1;
        }
    }

    return minCostPath(0, 0, arr, r, c, memo);
}

// DYNAMIC PROGRAMMING
int minCostPathDP(int **arr, int r, int c)
{
    int **output = new int *[r + 1];

    for (int i = 0; i <= r; i++)
    {
        output[i] = new int[c + 1];
    }

    output[r][c] = arr[r][c];

    for (int i = r; i >= 0; i--)
    {
        for (int j = c; j >= 0; j--)
        {
            if (i == r && j == c)
                continue;

            int x = INT_MAX, y = INT_MAX, z = INT_MAX;

            if (i + 1 <= r)
            {
                x = output[i + 1][j];
            }

            if (j + 1 <= c)
            {
                y = output[i][j + 1];
            }

            if (j + 1 <= c && i + 1 <= r)
            {
                z = output[i + 1][j + 1];
            }

            output[i][j] = min(x, min(y, z)) + arr[i][j];
        }
    }

    return output[0][0];
}

int main()
{
    int r, c;

    cin >> r >> c;

    int **arr = new int *[r];

    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << minCostPathDP(arr, r - 1, c - 1) << endl;

    return 0;
}