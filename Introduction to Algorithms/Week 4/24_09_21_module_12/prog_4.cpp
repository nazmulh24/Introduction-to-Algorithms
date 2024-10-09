//--> Matrix to Adjacency List

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

    int n;
    cin >> n;

    int mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // vector<int> v[n];
    vector<pair<int, int> > v[n];              //--> Weight thakle

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if (mat[i][j] == 1 && i!= 0)
            //     v[i].pb(j);

            if (mat[i][j] > 0)                    //--> Weight thakle
                v[i].pb(mp(j, mat[i][j]));
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";

        for (auto child : v[i])
        {
            // cout << child<< " ";

            cout << "{" << child.first << ", " << child.second << "} "; //--> Weight thakle
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
