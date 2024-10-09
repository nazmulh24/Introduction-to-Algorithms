//--> Can Go Again?

#include <bits/stdc++.h>
#define ll long long int
#define INF 10e17
using namespace std;

class Edge
{
public:
    int u, v;
    ll c;

    Edge(int u, int v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1001;
ll dis[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    while (e--)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;

        edgeList.push_back(Edge(a, b, w));
    }

    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    int s;
    cin >> s;

    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            ll c = ed.c;

            if (dis[u] < INF && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }

    bool cycle = false;

    for (auto ed : edgeList)
    {
        int u = ed.u;
        int v = ed.v;
        ll c = ed.c;

        if (dis[u] < INF && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        exit(0);
    }

    int t;
    cin >> t;

    while (t--)
    {
        int d;
        cin >> d;

        if (dis[d] == INF)
            cout << "Not Possible" << endl;
        else
            cout << dis[d] << endl;
    }

    return 0;
}
