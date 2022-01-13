#include <bits/stdc++.h>
using namespace std;

void print(int n, bool **edges, int sv)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << endl;

        for (int i = 0; i < n; i++)
        {
            if (i == front)
                continue;

            if (visited[i])
                continue;

            if (edges[front][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n;
    int e;
    cin >> n >> e;

    bool **edges = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = false;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = true;
        edges[s][f] = true;
    }

    print(n, edges, 0);

    return 0;
}