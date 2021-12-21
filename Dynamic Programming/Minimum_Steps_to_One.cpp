#include <bits/stdc++.h>
using namespace std;

/*
RECURSION
int minimumStepsToOne(int n)
{
    if (n == 1)
        return 0;

    int ans = INT_MAX;

    if (n > 1)
    {
        int temp = 1 + minimumStepsToOne(n - 1);
        if (temp < ans)
            ans = temp;
    }
    if (n % 2 == 0)
    {
        int temp = 1 + minimumStepsToOne(n / 2);
        if (temp < ans)
            ans = temp;
    }
    if (n % 3 == 0)
    {
        int temp = 1 + minimumStepsToOne(n / 3);
        if (temp < ans)
            ans = temp;
    }

    return ans;
}
*/

/*
MEMOIZATION
int minimumStepsToOne(int n, int *arr)
{
    if (n == 1)
        return 0;

    if (arr[n] != -1)
        return arr[n];

    int ans = INT_MAX;

    if (n > 1)
    {
        int temp = 1 + minimumStepsToOne(n - 1, arr);
        if (temp < ans)
            ans = temp;
    }
    if (n % 2 == 0)
    {
        int temp = 1 + minimumStepsToOne(n / 2, arr);
        if (temp < ans)
            ans = temp;
    }
    if (n % 3 == 0)
    {
        int temp = 1 + minimumStepsToOne(n / 3, arr);
        if (temp < ans)
            ans = temp;
    }

    arr[n] = ans;

    return ans;
}

int minimumStepsToOneHelper(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return minimumStepsToOne(n, arr);
}
*/

// DYNAMIC PROGRAMMING
int *minimumStepsToOne(int n)
{
    int *arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i <= n; i++)
        arr[i] = INT_MAX;

    for (int i = 2; i <= n; i++)
    {
        int y = INT_MAX, z = INT_MAX;

        int x = arr[i - 1];

        if (i % 2 == 0)
            y = arr[i / 2];

        if (i % 3 == 0)
            z = arr[i / 3];

        int ans = min(x, min(y, z)) + 1;

        arr[i] = ans;
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;

    int *arr = minimumStepsToOne(n);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << arr[i] << endl;
    }

    return 0;
}