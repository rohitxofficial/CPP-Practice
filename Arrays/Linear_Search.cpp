#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

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

        int x;
        cin >> x;

        int ans = LinearSearch(arr, n, x);

        cout << ans << endl;
    }

    return 0;
}