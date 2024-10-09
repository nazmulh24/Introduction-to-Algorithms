/***********************************************************************

Name --> Maze
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

#define PAIR pair<int, int>
const int N = 1001;

char mat[N][N];
bool vis[N][N];

map<PAIR, PAIR> parent;

vector<PAIR> d;
int n, m;

bool valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

void bfs(int si, int sj)
{
    queue<PAIR> q;
    q.push(mp(si, sj));

    vis[si][sj] = true;

    while (!q.empty())
    {
        PAIR node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = node.fi + d[i].fi;
            int cj = node.se + d[i].se;

            if (valid(ci, cj) && !vis[ci][cj] && (mat[ci][cj] == '.' || mat[ci][cj] == 'D'))
            {
                q.push(mp(ci, cj));

                vis[ci][cj] = true;
                parent[mp(ci, cj)] = mp(node.fi, node.se);
            }
        }
    }
}

void path(int di, int dj)
{
    int xi = di;
    int xj = dj;

    while (true)
    {
        int prev_i = parent[mp(xi, xj)].fi;
        int prev_j = parent[mp(xi, xj)].se;

        xi = prev_i;
        xj = prev_j;

        if (mat[xi][xj] == 'R')
            break;

        mat[xi][xj] = 'X';
    }
}

// void path(int di, int dj)
// {
//     int xi = di;
//     int xj = dj;

//     while (mat[xi][xj] != 'R')
//     {
//         if (mat[xi][xj] != 'D')
//             mat[xi][xj] = 'X';

//         PAIR prev_node = parent[mp(xi, xj)];

//         xi = prev_node.fi;
//         xj = prev_node.se;
//     }
// }

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void solve()
{
    d.pb(mp(0, 1));  //--> right
    d.pb(mp(0, -1)); //--> left
    d.pb(mp(-1, 0)); //--> up
    d.pb(mp(1, 0));  //--> down

    cin >> n >> m;

    int si, sj, di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if (mat[i][j] == 'R')
            {
                si = i;
                sj = j;
            }

            if (mat[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bfs(si, sj);

    if (vis[di][dj])
        path(di, dj);

    print();
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
