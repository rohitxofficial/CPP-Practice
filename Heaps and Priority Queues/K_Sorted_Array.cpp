#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = 0; i < n; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
        if (i + k < n)
            pq.push(arr[i + k]);
    }

    return 0;
}