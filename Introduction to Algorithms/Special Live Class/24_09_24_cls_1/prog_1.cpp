/***********************************************************************

Kruskal's Algorithm ---- MST

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
    for (int i = 0; i < n; i++)
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
        sz[leaderA] = sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] = sz[leaderA];
    }
}

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

bool cmp(Edge X, Edge Y)
{
    return (X.c < Y.c);
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

    int tcost = 0;

    for (auto ed : edgeList)
    {
        int leaderA = dsu_find(ed.a);
        int leaderB = dsu_find(ed.b);

        if (leaderA == leaderB)
            continue;
        else
        {
            dsu_union(ed.a, ed.b);

            cout << ed.a << " " << ed.b << " " << ed.c << endl;
            tcost += ed.c;
        }
    }

    cout << tcost << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t; // Uncomment if multiple test cases

    while (t--)
        solve();

    return 0;
}
