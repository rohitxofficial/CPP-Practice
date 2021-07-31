/*
Given a 2D interger array of size m*n, find and print
the sum of ith column elements separated by space.
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int m, n;
    cin >> m >> n;

    int sum[n] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sum[j] += arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << sum[i] << " ";
    }

    return 0;
}