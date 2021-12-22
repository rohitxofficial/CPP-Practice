#include <bits/stdc++.h>
using namespace std;

/*
MEMOIZATION
int numberOfBalancedBinaryTrees(int n, int *arr)
{
    if (n <= 1)
        return 1;

    if (arr[n] != -1)
        return arr[n];

    int mod = (int)(pow(10, 9)) + 7;

    int x = numberOfBalancedBinaryTrees(n - 1, arr);

    int y = numberOfBalancedBinaryTrees(n - 2, arr);

    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2 * (long long)(x)*y) % mod);

    int ans = (temp1 + temp2) % mod;

    arr[n] = ans;

    return ans;
}

int numberOfBalancedBinaryTreesHelper(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return numberOfBalancedBinaryTrees(n, arr);
}
*/

// DYNAMIC PROGRAMMING
int numberOfBalancedBinaryTrees(int n)
{
    int x = 1;
    int y = 1;

    int mod = (int)(pow(10, 9)) + 7;

    for (int i = 2; i <= n; i++)
    {
        int temp1 = (int)(((long long)(x)*x) % mod);
        int temp2 = (int)((2 * (long long)(x)*y) % mod);

        int ans = (temp1 + temp2) % mod;

        y = x;
        x = ans;
    }

    return x;
}

int main()
{
    int n;
    cin >> n;

    cout << numberOfBalancedBinaryTrees(n) << endl;

    return 0;
}