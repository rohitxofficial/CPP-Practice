#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int s;
    int d;
    int w;
};

bool compare(const edge &e1, const edge &e2)
{
    return e1.w < e2.w;
}

int main()
{
    int n, e;
    cin >> n >> e;

    // input array
    edge *input = new edge[e];

    for (int i = 0; i < e; i++)
    {
        cin >> input[i].s >> input[i].d >> input[i].w;
    }

    // sorting with Weight as value
    sort(input, input + e, compare);

    // output array
    edge *output = new edge[n - 1];

    // parent array
    int *parent = new int[n];

    // initializing parent array
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int v1 = input[i].s;
        int v2 = input[i].d;

        int parent_v1 = parent[v1];
        int parent_v2 = parent[v2];

        // finding top parent for v1
        while (parent[parent_v1] != parent_v1)
        {
            parent_v1 = parent[parent_v1];
        }

        // finding top parent for v2
        while (parent[parent_v2] != parent_v2)
        {
            parent_v2 = parent[parent_v2];
        }

        // if both parents are same, will form loop so continue
        if (parent_v1 == parent_v2)
        {
            continue;
        }
        // else both parents are different, i.e. disconnected componenets so add to ouput array and make changes to parent array.
        else
        {
            output[count] = input[i];
            count++;

            parent[parent_v2] = parent_v1;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << output[i].s << " " << output[i].d << " " << output[i].w << endl;
    }

    return 0;
}