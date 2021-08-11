/*
Given an array of length n and an integer x, you need 
to find if x is present in the array or not. Return true or false.
*/

#include <iostream>
using namespace std;

bool CheckNumber(int arr[], int n, int x)
{
    if (n == 1)
    {
        return (arr[0] == x) ? true : false;
    }

    if (arr[0] == x)
    {
        return true;
    }

    return CheckNumber(arr + 1, n - 1, x);
}

int main()
{
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    if (CheckNumber(arr, n, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}