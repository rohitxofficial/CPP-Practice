#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> subset;

    int max = 0;
    int sum = 0;
    int st = 0;
    int en = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            int temp_max = i + 1;
            if (temp_max > max)
            {
                max = temp_max;
                st = 0;
                en = i;
            }
        }
        else if (subset.count(sum) > 0)
        {
            // present
            if (max < (i - subset[sum]))
            {
                max = i - subset[sum];
                st = subset[sum] + 1;
                en = i;
            }
        }
        else
        {
            subset[sum] = i;
        }
    }

    cout << max << endl;
    cout << st << " " << en << endl;

    return 0;
}