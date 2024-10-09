//--> Road Construction - CSES
//--> https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int par[N];
int sz[N];

int n, m;
int cmp, mx;

void dsu_initialization(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }

    mx = INT_MIN;
    cmp = n;
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_SZ(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);

    if (leaderA == leaderB)
        return;

    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];

        mx = max(mx, sz[leaderA]);
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];

        mx = max(mx, sz[leaderB]);
    }

    cmp--;
}

int main()
{
    cin >> n >> m;

    dsu_initialization(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        dsu_union_SZ(a, b);

        cout << cmp << " " << mx << endl;
    }

    return 0;
}
