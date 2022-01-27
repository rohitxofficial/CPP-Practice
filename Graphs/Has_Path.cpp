#include <bits/stdc++.h>
using namespace std;

bool hasPath(int n, bool **edges, bool *visited, int v1, int v2)
{
    if (v1 == v2)
        return true;

    visited[v1] = true;

    bool ans = false;

    for (int i = 0; i < n; i++)
    {
        if (i == v1)
            continue;

        if (visited[i])
            continue;

        if (edges[v1][i])
            if (hasPath(n, edges, visited, i, v2))
                return true;
    }
    return false;
}

int main()
{
    int v;
    cin >> v;

    int e;
    cin >> e;

    bool **edges = new bool *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new bool[v];
        for (int j = 0; j < v; j++)
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

    bool *visited = new bool[v]{false};

    if (hasPath(v, edges, visited, v1, v2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}