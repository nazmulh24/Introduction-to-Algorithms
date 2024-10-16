/***********************************************************************

Name --> Perfect Balancer
Link --> Nazmul Hossain

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

    vector<int> a(n);
    int ts = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ts += a[i];
    }

    // cout << ts << endl;

    int ls = 0;

    for (int i = 0; i < n; ++i)
    {
        ts -= a[i];

        if (ls == ts)
        {
            cout << ls + a[i] << " " << i + 1 << endl;
            return;
        }

        ls += a[i];
    }

    cout << "UNSTABLE" << endl;
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
