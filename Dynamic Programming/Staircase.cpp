#include <bits/stdc++.h>
using namespace std;

/*
MEMOIZATION
int staircase(int n, int *arr)
{
    if (n == 0)
        return 1;

    if (arr[n] != -1)
        return arr[n];

    int ans = 0;

    ans += staircase(n - 1, arr);

    if (n - 2 >= 0)
        ans += staircase(n - 2, arr);

    if (n - 3 >= 0)
        ans += staircase(n - 3, arr);

    arr[n] = ans;

    return ans;
}

int staircaseHelper(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
        arr[i] = -1;

    return staircase(n, arr);
}
*/

// DYNAMIC PROGRAMMING
int staircase(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int ans = arr[i - 1];

        if (i - 2 >= 0)
            ans += arr[i - 2];

        if (i - 3 >= 0)
            ans += arr[i - 3];

        arr[i] = ans;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    cout << staircase(n) << endl;

    return 0;
}