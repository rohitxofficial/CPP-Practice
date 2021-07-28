#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int p1 = 0;
    int p2 = 0;

    while (p1 < n && p2 < n)
    {
        if (arr[p1] != 0)
        {
            if (p1 > p2)
            {
                int temp = arr[p1];
                arr[p1] = arr[p2];
                arr[p2] = temp;
            }
        }

        if (arr[p2] != 0)
        {
            p2++;
        }
        p1++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}