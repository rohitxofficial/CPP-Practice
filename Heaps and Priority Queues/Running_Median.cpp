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

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    if (n < 1)
        return 0;
    else
        max_pq.push(arr[0]);

    cout << arr[0] << endl;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < max_pq.top())
        {
            max_pq.push(arr[i]);
        }
        else
        {
            min_pq.push(arr[i]);
        }

        int absValue = max_pq.size() - min_pq.size();

        if (abs(absValue) > 1)
        {
            if (max_pq.size() > min_pq.size())
            {
                int top = max_pq.top();
                max_pq.pop();
                min_pq.push(top);
            }
            else
            {
                int top = min_pq.top();
                min_pq.pop();
                max_pq.push(top);
            }
        }

        if (max_pq.size() == min_pq.size())
            cout << (min_pq.top() + max_pq.top()) / 2 << endl;
        else if (max_pq.size() > min_pq.size())
            cout << max_pq.top() << endl;
        else
            cout << min_pq.top() << endl;
    }

    return 0;
}