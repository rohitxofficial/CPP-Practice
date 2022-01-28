#include <bits/stdc++.h>
using namespace std;

bool getPath(int n, bool **edges, bool *visited, int v1, int v2)
{
    if (v1 == v2)
    {
        cout << v1 << " ";
        return true;
    }

    visited[v1] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == v1)
            continue;

        if (visited[i])
            continue;

        if (edges[v1][i])
            if (getPath(n, edges, visited, i, v2))
            {
                cout << v1 << " ";
                return true;
            }
    }
    return false;
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
        int a, b;
        cin >> a >> b;

        edges[a][b] = true;
        edges[b][a] = true;
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool *visited = new bool[n]{false};

    getPath(n, edges, visited, v1, v2);

    cout << endl;

    return 0;
}