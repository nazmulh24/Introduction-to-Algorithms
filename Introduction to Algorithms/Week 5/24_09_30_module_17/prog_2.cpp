/***********************************************************************

Name -->  0-1 Knapsack Top Down Approach

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

const int maxN = 1e3 + 3;
const int maxW = 1e3 + 3;

int dp[maxN][maxW];

int knapsack(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n] <= w)
    {
        //--> 2 ta option --> niye dekhbo + na niye dekhbo...

        int op1 = knapsack(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];

        int op2 = knapsack(n - 1, weight, value, w);

        return dp[n][w] = max(op1, op2);
    }
    else
    {
        //--> akta option  --> na niyei dekhbo...

        int op2 = knapsack(n - 1, weight, value, w);

        return dp[n][w] = op2;
    }
}

void solve()
{
    int n;
    cin >> n;

    int weight[n], value[n];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    int w;
    cin >> w;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = knapsack(n, weight, value, w);

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
