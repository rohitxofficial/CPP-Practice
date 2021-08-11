/*
Given an array of length n and an integer x, you need to find and return the first index 
of integer x present in the array. Return -1 if it is not present in the array. 
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
*/

#include <iostream>
using namespace std;

int FirstIndex(int arr[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }

    if (arr[0] == x)
    {
        return 0;
    }

    int FirstIndexAns = FirstIndex(arr + 1, n - 1, x);

    if (FirstIndexAns != -1)
    {
        return 1 + FirstIndexAns;
    }
    else
    {
        return FirstIndexAns;
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

    cout << FirstIndex(arr, n, x);

    return 0;
}