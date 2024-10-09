/***********************************************************************

Name --> Subset Sum Bottom Up
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

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum;
    cin >> sum;

    bool dp[n + 1][sum + 1];

    dp[0][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
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

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i][j])
                cout << "T" << " ";
            else
                cout << "F" << " ";
        }
        cout << endl;
    }

    // if (dp[n][sum])
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
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
