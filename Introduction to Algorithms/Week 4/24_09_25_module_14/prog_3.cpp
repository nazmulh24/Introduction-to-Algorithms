/***********************************************************************

Name --> Commandos
Link --> https://lightoj.com/problem/commandos

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

vector<int> v[N];

bool vis[N];

int dis_from_src[N];
int dis_from_des[N];

void bfs(int s, int track)
{
    queue<int> q;
    q.push(s);

    if (track == 1)
        dis_from_src[s] = 0;
    else if (track == 2)
        dis_from_des[s] = 0;

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

                if (track == 1)
                    dis_from_src[child] = dis_from_src[par] + 1;
                else if (track == 2)
                    dis_from_des[child] = dis_from_des[par] + 1;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        v[a].pb(b);
        v[b].pb(a);
    }

    int s, d;
    cin >> s >> d;

    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        dis_from_src[i] = -1;
    }
    bfs(s, 1);

    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        dis_from_des[i] = -1;
    }
    bfs(d, 2);

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int val = dis_from_des[i] + dis_from_src[i];

        ans = max(val, ans);
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
        v[i].clear();
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
