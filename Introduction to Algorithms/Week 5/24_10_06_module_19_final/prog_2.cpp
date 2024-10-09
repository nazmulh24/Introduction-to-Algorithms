/***********************************************************************

Name --> Make It
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

int input;

int dp[100001];

bool rec(int cur)
{
    if (input < cur)
        return false;

    if (input == cur)
        return true;

    if (dp[cur] != -1)
        return dp[cur];

    bool op1 = rec(cur + 3);
    bool op2 = rec(cur * 2);

    return dp[cur] = (op1 || op2);
}

void solve()
{
    cin >> input;

    memset(dp, -1, sizeof(dp));

    bool flag = rec(1);

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t; // Uncomment if multiple test cases

    while (t--)
    {
        solve();
    }

    return 0;
}
