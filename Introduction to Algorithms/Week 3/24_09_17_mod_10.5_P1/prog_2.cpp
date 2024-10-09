//--> CSES - Building Roads
//--> https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int par[N];
int sz[N];

int n, m;

void dsu_init(int n)
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

void dsu_cycle(int nodeA, int nodeB)
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
    cin >> n >> m;

    dsu_init(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        dsu_cycle(a, b);
    }

    vector<int> leader;

    for (int i = 1; i <= n; i++)
    {
        if (par[i] == -1)
            leader.push_back(i);
    }

    cout << leader.size() - 1 << endl;

    for (int i = 1; i < leader.size(); i++)
    {
        cout << leader[i - 1] << " " << leader[i] << endl;
    }

    return 0;
}
