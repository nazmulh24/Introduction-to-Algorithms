//--> Union of -> Disjoint Set Union (DSU)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];

void dsu_initialize(int n)
{
    memset(par, -1, sizeof(par));

    par[1] = 2;
    par[2] = 3;
    par[5] = 6;
    par[6] = 7;
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;

    //--> Path compression optimization
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    par[leaderA] = leaderB;
}

int main()
{
    int n = 8;

    dsu_initialize(n);

    dsu_union(1, 5);

    cout << dsu_find(0) << endl;
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;
    cout << dsu_find(4) << endl;
    cout << dsu_find(5) << endl;
    cout << dsu_find(6) << endl;
    cout << dsu_find(7) << endl;

    return 0;
}
