//--> CSES - Road Reparation
//--> https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edge a, Edge b)
{
    return (a.c < b.c);
}

const int N = 1e5 + 1;
int par[N];
int sz[N];

void dsu_initi(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
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

void dsu_union(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);

    if (leaderA == leaderB)
        return;

    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsu_initi(n);

    vector<Edge> edge_list;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }

    sort(edge_list.begin(), edge_list.end(), cmp);

    long long tCost = 0;
    int edgeUsed = 0;

    for (Edge ed : edge_list)
    {
        int leaderA = dsu_find(ed.a);
        int leaderB = dsu_find(ed.b);

        if (leaderA != leaderB)
        {
            dsu_union(ed.a, ed.b);

            tCost = tCost + (long long)ed.c;
            edgeUsed++;

            if (edgeUsed == n - 1)
                break;
        }
    }

    if (edgeUsed == n - 1)
        cout << tCost << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
