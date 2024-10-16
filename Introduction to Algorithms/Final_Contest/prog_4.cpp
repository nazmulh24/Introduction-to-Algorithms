/***********************************************************************

Name --> Range Sum or Pain Sum
Link --> https://www.hackerrank.com/xpsc-final-contest-a-batch-05

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
    int n, q;
    cin >> n >> q;

    vector<int> v;
    for (int i = 1; i <= n / 2; ++i)
    {
        v.pb(i);
        v.pb(i);
    }

    vector<int> prefix_sum_1(n);
    prefix_sum_1[0] = v[0];

    for (int i = 1; i < n; i++)
        prefix_sum_1[i] = v[i] + prefix_sum_1[i - 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        int sum = (l == 0) ? prefix_sum_1[r] : prefix_sum_1[r] - prefix_sum_1[l - 1];

        cout << sum << endl;
    }
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
