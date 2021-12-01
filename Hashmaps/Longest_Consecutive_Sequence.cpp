#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    unordered_map<int, bool> status;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        status[arr[i]] = true;
    }

    pair<int, int> maxPair;
    int max = INT_MIN;
    int st = 0;
    int en = 0;

    for (int i = 0; i < n; i++)
    {
        if (status[arr[i]] == true)
        {
            status[arr[i]] = false;
            int tempmax = 1;
            st = arr[i];
            en = arr[i];

            int temp = arr[i] + 1;
            while (status.count(temp) > 0)
            {
                status[temp] = false;
                tempmax++;
                en++;
                temp++;
            }

            temp = arr[i] - 1;
            while (status.count(temp) > 0)
            {
                status[temp] = false;
                tempmax++;
                st--;
                temp--;
            }

            if (tempmax > max)
            {
                max = tempmax;
                maxPair = {st, en};
            }
        }
    }

    if (maxPair.first == maxPair.second)
        cout << maxPair.first;
    else
        cout << maxPair.first << " " << maxPair.second << endl;

    return 0;
}