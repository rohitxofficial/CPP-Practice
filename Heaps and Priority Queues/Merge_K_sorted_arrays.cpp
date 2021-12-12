#include <bits/stdc++.h>
using namespace std;

struct S
{
    int element;
    int arr;
    int elementIndex;

    S(int n1, int n2, int n3) : element(n1), arr(n2), elementIndex(n3)
    {
    }

    bool operator<(const struct S &other) const
    {
        return element > other.element;
    }
};

int main()
{
    int k;
    cin >> k;

    int *arrSize = new int[k];
    int **arr = new int *[k];

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;

        int *smallArr = new int[n];

        for (int j = 0; j < n; j++)
        {
            cin >> smallArr[j];
        }

        arrSize[i] = n;
        arr[i] = smallArr;
    }

    priority_queue<S> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(S(arr[i][0], i, 0));
    }

    while (!pq.empty())
    {
        S top = pq.top();
        pq.pop();
        cout << top.element << " ";

        int belongTo = top.arr;
        int newIndex = top.elementIndex + 1;

        if (newIndex < arrSize[belongTo])
            pq.push(S(arr[belongTo][newIndex], belongTo, newIndex));
    }
    cout << endl;

    return 0;
}