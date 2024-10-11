/***********************************************************************

Name -->  Longest Common Subsequence -- Top Down (LCS)
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

int lcs(string a, int n, string b, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
    {
        int ans = lcs(a, n - 1, b, m - 1);

        return dp[n][m] = ans + 1;
    }
    else
    {
        int op1 = lcs(a, n - 1, b, m);
        int op2 = lcs(a, n, b, m - 1);

        return dp[n][m] = max(op1, op2);
    }
}

void solve()
{
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    memset(dp, -1, sizeof(dp));

    int ans = lcs(a, n, b, m);

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
