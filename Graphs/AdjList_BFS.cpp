#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int n, int m, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);

            vis[i] = 1;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                bfs.push_back(curr);

                for (int ele: adj[curr]) {
                    if (!vis[ele]) {
                        q.push(ele);
                        vis[ele] = 1;
                    }
                }
            }
        }
    }

    return bfs;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs = BFS(n, m, adj);

    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    cout << endl;

    return 0;
}