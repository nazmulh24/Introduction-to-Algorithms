/***********************************************************************

Name --> A. Perfect Permutation
Link --> https://codeforces.com/problemset/problem/233/A

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

    if (n % 2 == 1)
    {
        cout << "-1" << endl;
        return;
    }

    int ar[n];
    for (int i = 1; i <= n; i++)
    {
        ar[i] = i;
    }

    for (int i = 1; i <= n + 1; i++)
    {
        if (ar[i] == i)
        {
            swap(ar[i], ar[i + 1]);
            i++;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ar[i] << " ";
    cout << endl;
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
