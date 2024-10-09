/***********************************************************************

Name --> X. The maximum path-sum
Link --> https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X

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

int a[11][11];

int maxSum(int n, int m, int a[][11])
{
    if (n == 0 && m == 0)
        return a[0][0];

    if (n < 0 || m < 0)
        return LONG_MIN;

    int op1 = maxSum(n - 1, m, a);
    int op2 = maxSum(n, m - 1, a);

    return max(op1, op2) + a[n][m];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = maxSum(n - 1, m - 1, a);

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
