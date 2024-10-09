//--> Adjacency List to Matrix -2

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

//-------------------------------------------------------------

void convert(int n, vector<pair<int, int>> adj[])
{
    int mat[n][n];

    memset(mat, -1, sizeof(mat));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mat[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            int node = child.first;
            int cost = child.second;

            mat[i][node] = cost;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    //------------------> Your code here

    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> v[n];

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(make_pair(b, c));
        // v[b].push_back(make_pair(a, c));
    }

    convert(n, v);
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
