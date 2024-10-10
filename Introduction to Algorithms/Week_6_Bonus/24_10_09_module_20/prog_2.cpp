/***********************************************************************

Name --> Unbounded Knapsack Implementation --> Bottom-Up
Link -->

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

void solve()
{
    int n, w;
    cin >> n >> w;

    int value[n];
    int weight[n];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i - 1] <= j)
            {
                int op1 = value[i - 1] + dp[i][j - weight[i - 1]];
                int op2 = dp[i - 1][j];

                dp[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = dp[i - 1][j];

                dp[i][j] = op2;
            }
        }
    }

    int ans = dp[n][w];

    cout << ans << endl;
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
