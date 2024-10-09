/***********************************************************************

Name --> D. Roads not only in Berland
Link --> https://codeforces.com/problemset/problem/25/D

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
    int n;
    cin >> n;

    dsu_initi(n);

    vector<pair<int, int>> bad;
    vector<pair<int, int>> notun;

    int x = n - 1;
    while (x--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            bad.pb(mp(a, b));
        else
            dsu_union(a, b);
    }

    for (int i = 2; i <= n; i++)
    {
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(i);

        if (leaderA != leaderB)
        {
            notun.pb(mp(1, i));
            dsu_union(1, i);
        }
    }

    cout << bad.size() << endl;

    for (int i = 0; i < bad.size(); i++)
    {
        cout << bad[i].fi << " " << bad[i].se << " " << notun[i].fi << " " << notun[i].se << endl;
    }
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
