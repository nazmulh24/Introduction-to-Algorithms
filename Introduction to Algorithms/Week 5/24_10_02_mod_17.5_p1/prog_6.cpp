/***********************************************************************

Name --> SPOJ.com - Problem FARIDA
Link --> https://www.spoj.com/problems/FARIDA/en/

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

int dp[10005];

int maxCoin(int n, int a[])
{
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int op1 = a[n] + maxCoin(n - 2, a);
    int op2 = maxCoin(n - 1, a);

    return dp[n] = max(op1, op2);
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

    int ans = maxCoin(n - 1, a);

    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t; // Uncomment if multiple test cases

    int x = 1;
    while (t--)
    {
        cout << "Case " << x << ": ";
        solve();
        x++;
    }

    return 0;
}
