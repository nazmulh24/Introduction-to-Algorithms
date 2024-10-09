//--> Cycle Detection using DSU

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int par[N];
int g_sz[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        g_sz[i] = 1;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void union_by_size(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);

    if (g_sz[leaderA] > g_sz[leaderB])
    {
        par[leaderB] = leaderA;
        g_sz[leaderA] += g_sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        g_sz[leaderB] += g_sz[leaderA];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            cycle = true;
        else
            union_by_size(a, b);
    }

    if (cycle)
        cout << "Cycle Ditected..." << endl;
    else
        cout << "Cycle Not Ditected..." << endl;

    return 0;
}
