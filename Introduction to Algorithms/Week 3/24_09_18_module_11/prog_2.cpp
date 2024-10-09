//--> Cycle Detection using DSU __MST

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return (a.c < b.c);
}

const int N = 1e5 + 5;
int par[N];
int siz[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        siz[i] = 1;
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

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (siz[leaderA] > siz[leaderB])
    {
        par[leaderB] = leaderA;
        siz[leaderA] += siz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        siz[leaderB] += siz[leaderA];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    vector<Edge> edge_list;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }

    sort(edge_list.begin(), edge_list.end(), cmp);

    int tCost = 0;

    for (Edge ed : edge_list)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);

        if (leaderU == leaderV)
            continue;
        else
        {
            dsu_union_by_size(ed.u, ed.v);

            cout << ed.u << " " << ed.v << " " << ed.c << endl;
            tCost += ed.c;
        }
    }

    cout << tCost << endl;

    return 0;
}
