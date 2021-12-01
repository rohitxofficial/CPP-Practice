#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    unordered_map<int, int> pairSum;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pairSum[arr[i]]++;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (pairSum.count(-arr[i]) > 0)
                count += pairSum[-arr[i]];
        }
    }

    cout << count << endl;

    return 0;
}