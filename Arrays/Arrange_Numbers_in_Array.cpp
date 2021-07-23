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