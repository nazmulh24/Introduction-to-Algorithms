/***********************************************************************

Name --> Guilty Prince
Link --> https://lightoj.com/problem/guilty-prince

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

#define PAIR pair<int, int>

const int N = 21;
char mat[N][N];
bool vis[N][N];

vector<PAIR> d;

int n, m;
bool valid(int ci, int cj)
{
    return (ci >= 0 && cj >= 0 && ci < n && cj < m);
}

int cnt;

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].fi;
        int cj = sj + d[i].se;

        if (valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

void solve()
{
    d.pb(mp(0, 1));
    d.pb(mp(0, -1));
    d.pb(mp(1, 0));
    d.pb(mp(-1, 0));

    cin >> m >> n;

    int si, sj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if (mat[i][j] == '@')
            {
                si = i;
                sj = j;
            }
        }
    }

    cnt = 0;

    memset(vis, false, sizeof(vis));

    dfs(si, sj);

    cout << cnt << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t; // Uncomment if multiple test cases

    int n = 1;
    while (t--)
    {
        cout << "Case " << n << ": ";
        solve();
        n++;
    }

    return 0;
}
