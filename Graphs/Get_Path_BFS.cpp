#include <bits/stdc++.h>
using namespace std;

void getPath(int n, bool **edges, int v1, int v2)
{
    bool *visited = new bool[n]{false};

    queue<int> q;
    q.push(v1);
    visited[v1] = true;

    vector<int> path;
    bool hasPath = false;

    while (!q.empty())
    {
        int curr = q.front();
        path.push_back(curr);
        if (curr == v2)
        {
            hasPath = true;
            break;
        }
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == curr)
                continue;

            if (visited[i])
                continue;

            if (edges[curr][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    if (hasPath)
    {
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
    }
    cout << endl;
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

    getPath(n, edges, v1, v2);

    return 0;
}