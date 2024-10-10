/***********************************************************************

Name --> Water
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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int li = -1, ri = -1;
    int lv = INT_MIN;
    int rv = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > lv)
        {
            rv = lv;
            ri = li;
            lv = arr[i];
            li = i;
        }
        else if (arr[i] > rv && arr[i] < lv)
        {
            rv = arr[i];
            ri = i;
        }
    }

    if (li < ri)
        cout << li << " " << ri << endl;
    else
        cout << ri << " " << li << endl;
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

//     rv = -1 |----| ri = -1 |----| lv = -1 |----| li = -1;
// n=0--> rv = -1 |----| ri = -1 |----| lv = 1 |----| li = 0;
// n=1--> rv = 1 |----| ri = 0 |----| lv = 8 |----| li = 1;
// n=2--> rv = 3 |----| ri = 2
// n=3--> rv = 4 |----| ri = 3
// n=4-->
// n=5--> rv = 8 |----| ri = 1 |----| lv = 7 |----| li = 5;
// n=6-->
// n=7-->
// n=8-->

// li = 5 <---> ri = 1