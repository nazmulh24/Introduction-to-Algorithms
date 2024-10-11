/***********************************************************************

Name --> Longest Common Substring Bottom Up and Printing
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
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                int ans = dp[i - 1][j - 1];

                dp[i][j] = ans + 1;
            }
            else
            {
                dp[i][j] = 0; //--> Change here...
            }
        }
    }

    int mx = 0;
    int ci, cj;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }

            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    string ans;
    while (ci != 0 && cj != 0)
    {
        if (a[ci - 1] == b[cj - 1])
        {
            ans += a[ci - 1];
            ci--;
            cj--;
        }
        else
            break;
    }

    reverse(ans.begin(), ans.end());

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
