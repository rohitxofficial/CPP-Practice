#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int count(int n, int *arr)
{
    if (n == 0)
        return 0;

    if (arr[n] != -1)
        return arr[n];

    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = 1 + count(n - i * i, arr);
        if (temp < ans)
            ans = temp;
    }

    arr[n] = ans;

    return ans;
}

int countHelper(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
        arr[i] = -1;

    return count(n, arr);
}

// DYNAMIC PROGRAMMING
int *countDP(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int minimum = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            int temp = 1 + arr[i - j * j];
            if (temp < minimum)
                minimum = temp;
        }
        arr[i] = minimum;
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;

    int *arr = countDP(n);
    for (int i = 1; i <= n; i++)
        cout << i << " : " << arr[i] << endl;

    return 0;
}