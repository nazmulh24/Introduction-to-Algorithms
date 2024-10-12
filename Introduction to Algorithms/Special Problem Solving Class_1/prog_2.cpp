/***********************************************************************

Name --> Palindrome Reorder
Link --> https://cses.fi/problemset/task/1755

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
    string s;
    cin >> s;

    map<char, int> cnt;

    int n = s.size();
    for (int i = 0; i < n; i++)
        cnt[s[i]]++; //--> Frequency Array...

    int odd_cnt = 0;
    for (auto val : cnt)
    {
        if (val.se % 2 != 0)
            odd_cnt++;
    }

    if (odd_cnt > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }

    string first, mid, last;

    for (auto val : cnt)
    {
        int key = val.fi;
        int occ = val.se;

        if (occ % 2 != 0)
        {
            for (int i = 1; i <= occ; i++)
            {
                mid.pb(key);
            }
        }
        else
        {
            for (int i = 1; i <= (occ / 2); i++)
            {
                first.pb(key);
                last.pb(key);
            }
        }
    }

    reverse(last.begin(), last.end());
    string ans = first + mid + last;

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
