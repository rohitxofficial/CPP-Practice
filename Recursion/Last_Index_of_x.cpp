/*
Given an array of length n and an integer x, you need to find and return the last index of integer 
x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
*/

#include <iostream>
using namespace std;

int LastIndex(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    int LastIndexValue = LastIndex(arr + 1, n - 1, x);

    if (arr[0] == x && LastIndexValue == -1)
    {
        return 0;
    }

    if (LastIndexValue != -1)
    {
        return 1 + LastIndexValue;
    }
    else
    {
        return LastIndexValue;
    }
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

    cout << LastIndex(arr, n, x) << endl;

    return 0;
}