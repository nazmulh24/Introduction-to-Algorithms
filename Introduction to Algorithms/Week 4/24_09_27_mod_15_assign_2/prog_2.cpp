/***********************************************************************

Name --> Building
Link --> Algorithm Assignment_2_m_15

***********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define UNIQUE(v) v.erase(unique(all(v)), v.end())
//********************************************************************

const int N = 1e5 + 5;

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

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge A, Edge B)
{
    return (A.w < B.w);
}

void solve()
{
    int n, e;
    cin >> n >> e;

    dsu_initi(n);

    vector<Edge> edgeList;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edgeList.pb(Edge(a, b, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    int tCost = 0;

    for (auto ed : edgeList)
    {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);

        if (leaderA != leaderB)
        {
            dsu_union(ed.u, ed.v);
            tCost += ed.w;
        }
    }

    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.pb(par[i]);
    }

    sort(v.begin(), v.end());

    bool flag = true;
    if (v[1] == -1)
        flag = false;

    if (flag)
        cout << tCost << endl;
    else
        cout << "-1" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t; // Uncomment if multiple test cases

    while (t--)
    {
        solve();
    }

    return 0;
}
