#include <bits/stdc++.h>
using namespace std;

void DFS(int n, bool **edges, bool *visited, int v)
{
    visited[v] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == v)
            continue;

        if (visited[i])
            continue;

        if (edges[v][i])
            DFS(n, edges, visited, i);
    }
}

bool isConnected(int n, bool **edges)
{
    bool *visited = new bool[n]{false};

    DFS(n, edges, visited, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

int main()
{
    int n, e;
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

    if (isConnected(n, edges))
        cout << "true";
    else
        cout << "false";

    return 0;
}