#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    unordered_map<int, int> status;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        status[arr[i]]++;
    }

    int k;
    cin >> k;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (status[arr[i]] > 0)
        {
            if (k == 0)
            {
                int num = status[arr[i]];
                status[arr[i]] = 0;
                ans += (num * (num - 1)) / 2;
            }
            else
            {
                int curr = status[arr[i]];
                status[arr[i]] = 0;
                int small = 0, big = 0;

                if (status.count(arr[i] - k) > 0)
                {
                    small = status[arr[i] - k];
                }

                if (status.count(arr[i] + k) > 0)
                {
                    big = status[arr[i] + k];
                }

                ans = ans + (curr * small) + (curr * big);
            }
        }
    }

    cout << ans << endl;

    return 0;
}