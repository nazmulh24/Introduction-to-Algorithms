/***********************************************************************

Name --> Subset Sum Top Down
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

int dp[1005][1005];

bool rec(int n, int a[], int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (a[n - 1] <= sum)
    {
        bool op1 = rec(n - 1, a, sum - a[n - 1]);
        bool op2 = rec(n - 1, a, sum);

        return dp[n][sum] = (op1 || op2);
    }
    else
    {
        bool op2 = rec(n - 1, a, sum);

        return dp[n][sum] = op2;
    }
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    int sum;
    cin >> sum;

    bool ans = rec(n, a, sum);

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
