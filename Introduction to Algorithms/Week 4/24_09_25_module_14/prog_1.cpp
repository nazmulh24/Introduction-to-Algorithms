/***********************************************************************

Name --> 10106 - Sundorban
Link --> https://school.outsbook.com/problems/problemdetails/10106

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

const int N = 31;

char mat[N][N];
bool vis[N][N];
int dis[N][N];
vector<PAIR> d;

int n;
bool valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < n);
}

void bfs(int si, int sj)
{
    queue<PAIR> q;
    q.push(mp(si, sj));

    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        PAIR par = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.fi + d[i].fi;
            int cj = par.se + d[i].se;

            if (valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != 'T')
            {
                q.push(mp(ci, cj));

                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.fi][par.se] + 1;
            }
        }
    }
}

void solve()
{
    d.pb(mp(0, 1));
    d.pb(mp(0, -1));
    d.pb(mp(1, 0));
    d.pb(mp(-1, 0));

    while (cin >> n)
    {
        int si, sj, di, dj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                cin >> mat[i][j];

                if (mat[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        bfs(si, sj);

        cout << dis[di][dj] << endl;
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
