#include <bits/stdc++.h>
using namespace std;

void BFS_helper(int n, bool **edges, bool *visited, int vertex)
{
    queue<int> pending;

    pending.push(vertex);
    visited[vertex] = true;

    while (!pending.empty())
    {
        int curr_vertex = pending.front();
        cout << curr_vertex << " ";

        pending.pop();

        for (int i = 0; i < n; i++)
        {
            if (curr_vertex == i)
                continue;

            if (visited[i])
                continue;

            if (edges[curr_vertex][i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int n, bool **edges)
{
    bool *visited = new bool[n]{false};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            BFS_helper(n, edges, visited, i);
    }
}

void DFS_helper(int n, bool **edges, bool *visited, int vertex)
{
    cout << vertex << " ";
    visited[vertex] = true;

    for (int i = 0; i < n; i++)
    {
        if (vertex == i)
            continue;

        if (visited[i])
            continue;

        if (edges[vertex][i])
            DFS_helper(n, edges, visited, i);
    }
}

void DFS(int n, bool **edges)
{
    bool *visited = new bool[n]{false};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS_helper(n, edges, visited, i);
    }
}

int main()
{
    int n;
    cout << "Enter Number of Vertices in Graph: ";
    cin >> n;

    int e;
    cout << "Enter Number of Edges in Graph: ";
    cin >> e;

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
        int e1, e2;
        cout << "Enter Vertex 1 of Edge " << i + 1 << " : ";
        cin >> e1;
        cout << "Enter Vertex 2 of Edge " << i + 1 << " : ";
        cin >> e2;

        edges[e1][e2] = true;
        edges[e2][e1] = true;
    }

    cout << "DFS : ";

    DFS(n, edges);

    cout << endl;

    cout << "BFS : ";

    BFS(n, edges);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}