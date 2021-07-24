/*
Given two integer arrays(arr1 and arr2) of size m and n, respectively. 
You need to print their intersection; An intersection for this problem 
can be defined when both the arrays contain a particular value or to put
it in other words, when there is a common value that exists in both the arrays.
*/

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr2[j] << " ";
                arr2[j] = INT_MIN;
                break;
            }
        }
    }

    return 0;
}