//--> C. Dijkstra? - Codeforces
//--> https://codeforces.com/problemset/problem/20/C

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
//---------------------------------------------------------------------

#define pi pair<int, int>

const int N = 1e5 + 5;
vector<pi> v[N];
bool vis[N];
int dis[N];
int parent[N];

class cmp
{
public:
    bool operator()(pi A, pi B)
    {
        return (A.se > B.se);
    }
};

void dijkstra(int s)
{
    priority_queue<pi, vector<pi>, cmp> pq;
    pq.push(mp(s, 0));

    dis[s] = 0;

    while (!pq.empty())
    {
        pi par = pq.top();
        pq.pop();

        int parNode = par.fi;
        int parCost = par.se;

        for (auto child : v[parNode])
        {
            int childNode = child.fi;
            int childCost = child.se;

            if (parCost + childCost < dis[childNode])
            {
                dis[childNode] = parCost + childCost;
                pq.push(mp(childNode, dis[childNode]));
                parent[childNode] = parNode;
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
        int a, b, c;
        cin >> a >> b >> c;

        v[a].pb(mp(b, c));
        v[b].pb(mp(a, c));
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }

    dijkstra(1);

    if (dis[n] == 1e18)
        cout << "-1" << endl;
    else
    {
        int x = n;
        vector<int> path;
        while (x != -1)
        {
            path.pb(x);
            x = parent[x];
        }

        reverse(path.begin(), path.end());

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
