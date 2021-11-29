#include <bits/stdc++.h>
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

    vector<int> ans;
    unordered_map<int, bool> myMap;

    for (int i = 0; i < n; i++)
    {
        if (myMap.count(arr[i]) == 0)
        {
            myMap[arr[i]] = true;
            ans.push_back(arr[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
