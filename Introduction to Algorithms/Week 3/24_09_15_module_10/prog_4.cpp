//--> Union By Size of -> Disjoint Set Union (DSU)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int lavel[N];

void dsu_initialize(int n)
{
    memset(par, -1, sizeof(par));

    for (int i = 0; i < n; i++)
    {
        lavel[i] = 0;
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

void dsu_union_by_lavel(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (lavel[leaderA] > lavel[leaderB])
        par[leaderB] = leaderA;
    else if (lavel[leaderB] > lavel[leaderA])
        par[leaderA] = leaderB;
    else
    {
        par[leaderA] = leaderB;
        lavel[leaderB]++;
    }
}

int main()
{
    int n = 7;

    dsu_initialize(n);

    dsu_union_by_lavel(1, 2);
    dsu_union_by_lavel(2, 3);
    dsu_union_by_lavel(4, 5);
    dsu_union_by_lavel(5, 6);
    dsu_union_by_lavel(1, 4);

    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}

