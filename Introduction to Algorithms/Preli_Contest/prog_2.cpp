/***********************************************************************

Name --> Find the Maximum even
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
        cin >> a[i];

    sort(a, a + n, greater<int>());

    int e1 = -1, e2 = -1, o1 = -1, o2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (e1 == -1)
                e1 = a[i];
            else if (e2 == -1)
                e2 = a[i];
        }
        else
        {
            if (o1 == -1)
                o1 = a[i];
            else if (o2 == -1)
                o2 = a[i];
        }

        if (e1 != -1 && e2 != -1 && o1 != -1 && o2 != -1)
            break;
    }

    int ans = -1;

    if (e1 != -1 && e2 != -1)
        ans = max(ans, e1 + e2);
    if (o1 != -1 && o2 != -1)
        ans = max(ans, o1 + o2);
    if (e1 != -1)
        ans = max(ans, e1);

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
