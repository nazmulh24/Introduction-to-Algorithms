/***********************************************************************

Name --> Unbounded Knapsack Implementation --> Top-Down
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

int dp[1001][1001];

int unbounded_knapsack(int n, int val[], int wei[], int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wei[n - 1] <= w)
    {
        int op1 = val[n - 1] + unbounded_knapsack(n, val, wei, w - wei[n - 1]);
        int op2 = unbounded_knapsack(n - 1, val, wei, w);

        return dp[n][w] = max(op1, op2);
    }
    else
    {
        int op2 = unbounded_knapsack(n - 1, val, wei, w);

        return dp[n][w] = op2;
    }
}

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

    memset(dp, -1, sizeof(dp));

    int ans = unbounded_knapsack(n, value, weight, w);

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
