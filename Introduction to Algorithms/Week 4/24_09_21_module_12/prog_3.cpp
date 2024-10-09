//--> Edge List to Matrix

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

void solve()
{
    //------------------> Your code here

    int n, e;
    cin >> n >> e;

    int mat[n][n];

    // memset(mat, 0, sizeof(mat));
    memset(mat, -1, sizeof(mat)); //--> Weighted

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if (i == j)
            //     mat[i][j] = 1;

            if (i == j) //--> Weighted
                mat[i][j] = 0;
        }
    }

    while (e--)
    {
        // int a, b;
        // cin >> a >> b;

        // mat[a][b] = 1;
        // mat[b][a] = 1;

        //--> Weighted-->
        int a, b, c;
        cin >> a >> b >> c;

        mat[a][b] = c;
        mat[b][a] = c;
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
