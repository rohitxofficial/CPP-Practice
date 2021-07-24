/*
Given an integer array(arr) of size n which contains numbers from 0 to (N - 2).
Each number is present at least once. That is, if n = 5, the array/list constitutes 
values ranging from 0 to 3 and among these, there is a single integer value that is present twice. 
You need to find and return that duplicate number present in the array.
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        int duplicate[n - 1] = {0};

        for (int j = 0; j < n; j++)
        {
            duplicate[arr[j]]++;
        }

        for (int j = 0; j < n - 1; j++)
        {
            if (duplicate[j] == 2)
            {
                cout << j << endl;
                break;
            }
        }
    }
}