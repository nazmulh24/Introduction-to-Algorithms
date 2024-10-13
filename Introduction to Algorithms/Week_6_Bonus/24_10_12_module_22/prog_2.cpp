/***********************************************************************

Name --> Divide Works in Merge Sort
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

void divide(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    if (l < r)
    {
        int mid = (l + r) / 2;
        divide(a, l, mid);
        divide(a, mid + 1, r);
    }
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    divide(a, 0, n - 1);
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
