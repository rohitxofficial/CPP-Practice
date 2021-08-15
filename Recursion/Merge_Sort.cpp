#include <iostream>
#include <climits>
using namespace std;

void Merge2Sorted(int arr[], int st, int en)
{
    int p1 = st;
    int p2 = ((st + en) / 2) + 1;

    int arr2[en - st + 1];
    int p3 = 0;
    while (p3 <= (en - st))
    {
        if (arr[p1] > arr[p2])
        {
            arr2[p3] = arr[p2];
            if (p2 < en)
                p2++;
            else
                arr[p2] = INT_MAX;
        }
        else
        {
            arr2[p3] = arr[p1];
            if (p1 < ((st + en) / 2))
                p1++;
            else
                arr[p1] = INT_MAX;
        }
        p3++;
    }

    for (int i = st; i <= en; i++)
    {
        arr[i] = arr2[i - st];
    }
}

void MergeSort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }

    MergeSort(arr, 0, (st + en) / 2);
    MergeSort(arr, ((st + en) / 2) + 1, en);

    Merge2Sorted(arr, st, en);
}

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    MergeSort(p, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    delete p;

    return 0;
}