/***********************************************************************

Name --> Mina & Moni
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

int n;
vector<int> vec;
int sum, half;

int dp[15][15007][10];

int f(int i, int crrSum, int coin)
{

    if (i == n)
    {
        if (coin == half)
            return abs((sum - crrSum) - crrSum);
        else
            return INT_MAX;
    }

    // if (i >= n or coin > half) return INT_MAX;

    if (dp[i][crrSum][coin] != -1)
        return dp[i][crrSum][coin];
    return dp[i][crrSum][coin] = min(f(i + 1, crrSum + vec[i], coin + 1),
                                     f(i + 1, crrSum, coin));
}

void solve()
{
    cin >> n;
    sum = 0;
    vec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    if (n == 1)
    {
        cout << vec[0] << endl;
        return;
    }

    half = (n / 2);
    if (n % 2)
        half++;

    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, 0) << endl;
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
