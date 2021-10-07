#include <iostream>
using namespace std;

int partition(int arr[], int st, int en)
{
    int pivot = arr[st];

    int small_count = 0;

    for (int i = st; i <= en; i++)
    {
        if (arr[i] < pivot)
            small_count++;
    }

    int temp = pivot;
    arr[st] = arr[st + small_count];
    arr[st + small_count] = temp;

    int p1 = st;
    int p2 = en;

    while (p1 < st + small_count && p2 > st + small_count)
    {
        if (arr[p1] < pivot)
        {
            p1++;
        }
        else if (arr[p2] > pivot)
        {
            p2--;
        }
        else
        {
            int temp2 = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = temp2;
            p1++;
            p2--;
        }
    }

    return st + small_count;
}

void sort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }

    int c = partition(arr, st, en);
    sort(arr, st, c - 1);
    sort(arr, c + 1, en);
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

    int target;
    cin >> target;

    sort(arr, 0, n - 1);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int target_sum = target - arr[i];

        int count = 0;
        int p1 = i + 1;
        int p2 = n - 1;
        while (p1 < p2)
        {
            if (p1 == i)
            {
                p1++;
                continue;
            }

            if (p2 == i)
            {
                p2--;
                continue;
            }

            int sum = arr[p1] + arr[p2];
            if (sum < target_sum)
            {
                p1++;
            }
            else if (sum > target_sum)
            {
                p2--;
            }
            else
            {
                if (arr[p1] == arr[p2])
                {
                    int total = p2 - p1;
                    count += (total * (total + 1)) / 2;
                    break;
                }
                else
                {
                    int temp1 = 1;
                    while (arr[p1] == arr[p1 + 1])
                    {
                        temp1++;
                        p1++;
                    }
                    p1++;

                    int temp2 = 1;
                    while (arr[p2] == arr[p2 - 1])
                    {
                        temp2++;
                        p2--;
                    }
                    p2--;

                    count += temp1 * temp2;
                }
            }
        }
        ans += count;
    }

    cout << ans << endl;

    delete arr;
    return 0;
}
