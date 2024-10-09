//--> CSES - Message Route
//--> https://cses.fi/problemset/task/1667/

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
//----------------------------------------------------------------

const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
// int dis[N];
int parent[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    vis[s] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;

                parent[child] = par;
            }
        }
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        v[a].pb(b);
        v[b].pb(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bfs(1);

    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        for (int i = n; i != -1; i = parent[i])
            path.push_back(i);

        reverse(path.begin(), path.end());

        cout << path.size() << endl;

        for (auto u : path)
            cout << u << " ";
        cout << endl;
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
