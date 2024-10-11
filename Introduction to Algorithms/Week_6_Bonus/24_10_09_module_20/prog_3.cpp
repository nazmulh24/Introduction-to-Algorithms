/***********************************************************************

Name --> Rod Cutting Problem
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

int unbounded_knapsack(int n, int w, int val[], int weight[])
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n - 1] <= w)
    {
        int op1 = val[n - 1] + unbounded_knapsack(n, w - weight[n - 1], val, weight);
        int op2 = unbounded_knapsack(n - 1, w, val, weight);

        return dp[n][w] = max(op1, op2);
    }
    else
    {
        int op2 = unbounded_knapsack(n - 1, w, val, weight);

        return dp[n][w] = op2;
    }
}

void solve()
{
    int n;
    cin >> n;

    int val[n];
    int weight[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        weight[i] = i + 1;
    }

    memset(dp, -1, sizeof(dp));

    int ans = unbounded_knapsack(n, n, val, weight);

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
