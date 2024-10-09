//--> Romeo and Juliet - Hackerrank
//--> https://www.hackerrank.com/contests/phitron-monthly-programming-contest-a-batch-04-a-feb-2024/challenges/romeo-and-juliet-2

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
//--------------------------------------------------------------------

const int N = 2 * 1e5 + 5;
vector<int> v[N];
bool vis[N];
int dis[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    vis[s] = true;
    dis[s] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[par] + 1;
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
    memset(dis, -1, sizeof(dis));

    int x, y, k;
    cin >> x >> y >> k;

    bfs(x);

    if (dis[y] != -1 && dis[y] <= 2 * k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
