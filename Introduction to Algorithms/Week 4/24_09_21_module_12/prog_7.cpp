//-->  Adjacency List to Edge List

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

//-------------------------------------------------------------

class Edge //---> For Weight graph
{
public:
    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

void solve()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int> > v[n];  //--> For Wight Graph

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].pb(mp(b, c));  //--> For Wight Graph
    }

    vector<Edge> edgeList;  //--> For Wight Graph

    for (int i = 0; i < n; i++)
    {
        for (auto child : v[i])
        {
            int node = child.first;
            int cost = child.second;
            edgeList.pb(Edge(i, node, cost));
        }
    }

    for (auto edge : edgeList)
    {
        cout << edge.a << " " << edge.b << " " << edge.c << endl; //--> For Wight Graph
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
