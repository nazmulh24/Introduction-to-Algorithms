//--> CSES - Building Roads
//--> https://cses.fi/problemset/task/1666/

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
//---------------------------------------------------------------

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
        sz[leaderA] = sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] = sz[leaderA];
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;

    dsu_initi(n);

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA != leaderB)
            dsu_union(a, b);
    }

    vector<int> leader;

    // for (int i = 1; i <= n; i++)
    // {
    //     int x = dsu_find(i);
    //     leader.pb(x);
    // }
    // sort(leader.begin(), leader.end());
    // leader.erase(unique(leader.begin(), leader.end()), leader.end());

    //--> Alternative line 83-88 -->
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
