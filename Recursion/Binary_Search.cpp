#include <iostream>
using namespace std;

int BinarySearch(int arr[], int x, int st, int en)
{
    if (st > en)
    {
        return -1;
    }

    int mid = (st + en) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return BinarySearch(arr, x, st, mid - 1);
    }
    else
    {
        return BinarySearch(arr, x, mid + 1, en);
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << BinarySearch(arr, x, 0, n - 1) << endl;

    delete arr;
 
    return 0;
}