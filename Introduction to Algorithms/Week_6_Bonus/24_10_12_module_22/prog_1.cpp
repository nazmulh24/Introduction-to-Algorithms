/***********************************************************************

Name --> Marge Two Sorted Arrays Implementation
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

void merge(int l, int mid, int r, int a[])
{
    int ls = mid - l + 1;
    int rs = r - mid;

    int L[ls];
    int R[rs];

    int k = 0;
    for (int i = l; i <= mid; i++)
    {
        L[k] = a[i];
        k++;
    }

    k = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }

    int j;
    int i = j = 0;
    int cur = l;

    while (i < ls && j < rs)
    {
        if (L[i] <= R[j])
        {
            a[cur] = L[i];
            i++;
        }
        else
        {
            a[cur] = R[j];
            j++;
        }
        cur++;
    }

    while (i < ls)
    {
        a[cur] = L[i];
        i++;
        cur++;
    }

    while (j < rs)
    {
        a[cur] = R[j];
        j++;
        cur++;
    }
}

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    merge(0, 3, n, a);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
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
