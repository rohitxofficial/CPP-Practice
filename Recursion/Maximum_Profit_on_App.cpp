#include <iostream>
#include <climits>
using namespace std;

void merge2Sorted(int arr[], int st, int mid, int en)
{
    int p1 = st;
    int p2 = mid + 1;

    int temp[en - st + 1];
    int i = 0;
    while (i < (en - st + 1))
    {
        if (arr[p1] >= arr[p2])
        {
            temp[i] = arr[p2];
            if (p2 < en)
                p2++;
            else
                arr[p2] = INT_MAX;
        }
        else
        {
            temp[i] = arr[p1];
            if (p1 < mid)
                p1++;
            else
                arr[p1] = INT_MAX;
        }
        i++;
    }

    for (int i = st; i <= en; i++)
    {
        arr[i] = temp[i - st];
    }
}

void mergeSort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }

    int mid = (st + en) / 2;

    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, en);

    merge2Sorted(arr, st, mid, en);
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

    mergeSort(arr, 0, n - 1);

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int max_temp = (n - i) * arr[i];

        if (max_temp > max)
            max = max_temp;
    }

    cout << max << endl;

    delete arr;

    return 0;
}