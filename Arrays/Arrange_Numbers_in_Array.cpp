/*
You have been given an empty array(arr) and its size n.
The only input taken from the user will be n and 
you need not worry about the array. Your task is to populate the array
using the integer values in the range 1 to N(both inclusive) in the order (1,3,5,.......6,4,2).
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

        int start = 0;
        int end = n - 1;
        int seq = 1;
        int arr[n];

        while (seq <= n)
        {
            arr[start] = seq;
            start++;
            seq++;
            if (seq <= n)
            {
                arr[end] = seq;
                end--;
                seq++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
    }

    return 0;
}
