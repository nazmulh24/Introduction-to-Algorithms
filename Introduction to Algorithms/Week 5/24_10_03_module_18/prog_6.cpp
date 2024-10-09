/***********************************************************************

Name --> Minimum Subset Sum Difference
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
    int n;
    cin >> n;

    int s = 0;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    bool dp[n + 1][s + 1];

    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                bool op1 = dp[i - 1][j - a[i - 1]];
                bool op2 = dp[i - 1][j];

                dp[i][j] = op1 || op2;
            }
            else
            {
                bool op2 = dp[i - 1][j];

                dp[i][j] = op2;
            }
        }
    }

    vector<int> v;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            // if (dp[i][j] == 1)
            //     cout << j << " ";
            // else
            //     cout << dp[i][j] << " ";

            if (dp[i][j] == 1)
                v.pb(j);
        }
        // cout << endl;
    }

    int ans = INT_MAX;
    for (int val : v)
    {
        int s1 = val;
        int s2 = s - s1;

        ans = min(ans, abs(s1 - s2));
    }
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
