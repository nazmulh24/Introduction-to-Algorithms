/******************************************************************************

Problem Statement:
You live in a city where there are N buildings, and E roads connect those buildings. Each road has a distance, and they are two-way roads. You want to start a business in your city where you will provide ISP service. For that reason, you need to connect all buildings with your central wire cable through the roads. As the price of optical fiber is high, you want to reduce the cost as much as possible. If you know the distance of the roads, can you calculate the minimum cost to connect all buildings with your cable? The cost of optical fiber is equal to the distance of any road.

Sample Input:
6 10
0 1 5
0 2 6
0 3 8
0 4 6
0 5 10
3 5 2
5 1 4
1 2 3
2 4 8
4 3 6

Sample Output:
20

******************************************************************************/

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
//-------------------------------------------------------------------------------

const int N = 1e5 + 5;
int par[N];
int sz[N];

void dsu_initi(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);

    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] = sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] = sz[leaderA];
    }
}

class Edge
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

bool cmp(Edge A, Edge B)
{
    return (A.c < B.c);
}

void solve()
{
    int n, e;
    cin >> n >> e;

    dsu_initi(n);

    vector<Edge> edgeList;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edgeList.pb(Edge(a, b, c));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    int tcost = 0;

    for (auto ed : edgeList)
    {
        int leaderA = dsu_find(ed.a);
        int leaderB = dsu_find(ed.b);

        if (leaderA == leaderB)
            continue;
        else
        {
            dsu_union(ed.a, ed.b);

            tcost += ed.c;
        }
    }

    cout << tcost << endl;
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
