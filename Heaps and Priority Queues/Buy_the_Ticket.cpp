#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    int k;
    cin >> k;

    int time = 0;
    int i = 0;
    while (true)
    {
        if (i == k && arr[i] == pq.top())
        {
            time++;
            break;
        }
        else if (arr[i] == pq.top())
        {
            pq.pop();
            time++;
        }

        i++;
        if (i == n)
            i = 0;
    }

    cout << time << endl;

    return 0;
}