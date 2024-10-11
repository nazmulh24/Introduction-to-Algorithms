/***********************************************************************

Name --> Coin Change 2
Link --> Sum hote minimum number of coin found-->(Un-bounded_subset)

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
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s;
    cin >> s;

    int dp[n + 1][s + 1];

    dp[0][0] = 0;
    for (int i = 1; i <= s; i++)
        dp[0][i] = INT_MAX - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                int op1 = 1 + dp[i][j - a[i - 1]]; //--> change here
                int op2 = dp[i - 1][j];

                dp[i][j] = min(op1, op2);
            }
            else
            {
                int op2 = dp[i - 1][j];

                dp[i][j] = op2;
            }
        }
    }

    int ans = dp[n][s];

    if (ans == INT_MAX - 1)
        cout << "Not Possible" << endl;
    else
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
