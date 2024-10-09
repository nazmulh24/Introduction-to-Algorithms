/***********************************************************************

Name --> W. Reach Value
Link --> https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W

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

bool canReach(int curr)
{
    if (curr > input)
        return false;

    if (curr == input)
        return true;

    return (canReach(curr * 10) || canReach(curr * 20));
}

void solve()
{
    cin >> input;

    bool flag = canReach(1);

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
