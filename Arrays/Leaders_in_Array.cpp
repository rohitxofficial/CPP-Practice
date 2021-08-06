/*
Given an integer array arr of size n. Find and print all the leaders present in the input array. 
An array element arr[i] is called Leader, if all the elements following it (i.e. present at its right) are less than or equal to arr[i].
Print all the leader elements separated by space and in the same order they are present in the input array.
*/

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    int store[100];
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            store[count] = arr[i];
            count++;
        }
    }

    for (int i = count - 1; i >= 0; i--)
    {
        cout << store[i] << " ";
    }

    return 0;
}