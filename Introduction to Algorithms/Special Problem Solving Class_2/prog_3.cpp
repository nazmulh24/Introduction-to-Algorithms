/***********************************************************************

Name --> A. King Escape
Link --> https://codeforces.com/problemset/problem/1033/A

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

const int N = 1009;

int a[N][N];
int vis[N][N];

int n;
bool valid(int ci, int cj)
{
    return (ci >= 1 && ci <= n && cj >= 1 && cj <= n);
}

vector<pair<int, int>> d;

void bfs(int ki, int kj)
{
    queue<pair<int, int>> q;
    q.push(mp(ki, kj));

    vis[ki][kj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int x = par.fi;
        int y = par.se;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ci = d[i].fi + x;
            int cj = d[i].se + y;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push(mp(ci, cj));
            }
        }
    }
}

void solve()
{
    d.pb(mp(1, 0));
    d.pb(mp(-1, 0));
    d.pb(mp(0, 1));
    d.pb(mp(0, -1));
    d.pb(mp(1, 1));
    d.pb(mp(1, -1));
    d.pb(mp(-1, 1));
    d.pb(mp(-1, -1));

    cin >> n;

    int qi, qj, ki, kj, ci, cj;
    cin >> qi >> qj >> ki >> kj >> ci >> cj;

    for (int i = 0; i < 8; i++)
    {
        int x = d[i].fi + qi;
        int y = d[i].se + qj;
        while (valid(x, y))
        {
            vis[x][y] = true;

            x += d[i].fi;
            y += d[i].se;
        }
    }

    bfs(ki, kj);

    if (vis[ci][cj])
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
