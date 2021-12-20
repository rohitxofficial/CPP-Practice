#include <bits/stdc++.h>
using namespace std;

long long fibonacciHelper(int n, long long *&arr)
{
    if (n == 1)
        return 1;

    if (n == 0)
        return 0;

    if (arr[n] != -1)
        return arr[n];

    long long nSum = fibonacciHelper(n - 1, arr) + fibonacciHelper(n - 2, arr);

    arr[n] = nSum;

    return nSum;
}

long long fibonacci(int n)
{
    long long *arr = new long long[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return fibonacciHelper(n, arr);
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}