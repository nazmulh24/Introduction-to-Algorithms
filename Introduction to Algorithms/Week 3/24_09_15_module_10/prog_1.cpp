//--> Find Operation Implementation of -> Disjoint Set Union (DSU)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int par[N];

void dsu_initialize(int n)
{
    memset(par, -1, sizeof(par));

    par[1] = 3;
    par[2] = 1;
}

int find(int node)
{
    if (par[node] == -1)
        return node;

    //--> Naive implementation
    // return find(par[node]);

    //--> Path compression optimization
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

int main()
{
    int n = 4;

    dsu_initialize(n);

    cout << find(0) << endl;
    cout << find(1) << endl;
    cout << find(2) << endl;
    cout << find(3) << endl;

    return 0;
}
