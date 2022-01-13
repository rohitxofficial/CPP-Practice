#include <bits/stdc++.h>
using namespace std;

void print(int n, bool **edges, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;

        if (visited[i])
            continue;

        if (edges[sv][i])
            print(n, edges, i, visited);
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    print(n, edges, 0, visited);

    return 0;
}