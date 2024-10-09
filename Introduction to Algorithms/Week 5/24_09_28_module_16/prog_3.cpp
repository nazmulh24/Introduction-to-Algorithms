/***********************************************************************

Name --> Memoization on Fibonacci Series

***********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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

const int N = 1e5 + 5;
int dp[N];

int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    int ans = fibo(n - 1) + fibo(n - 2);
    dp[n] = ans;
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    int fibona = fibo(n);

    cout << fibona << endl;
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
