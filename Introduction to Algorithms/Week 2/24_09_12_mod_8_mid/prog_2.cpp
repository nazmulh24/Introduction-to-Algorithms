//--> Can Go?

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1001;
vector<pair<int, ll> > v[N];
ll dis[N];

class cmp
{
public:
    bool operator()(pair<int, ll> a, pair<int, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, ll>, vector<pair<int, ll> >, cmp> pq;
    pq.push(make_pair(src, 0));
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, ll> par = pq.top();
        pq.pop();
        int node = par.first;
        ll cost = par.second;

        if (cost > dis[node])
            continue;

        for (pair<int, ll> child : v[node])
        {
            int c_node = child.first;
            ll c_cost = child.second;

            if (cost + c_cost < dis[c_node])
            {
                dis[c_node] = cost + c_cost;
                pq.push(make_pair(c_node, dis[c_node]));
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        v[a].push_back(make_pair(b, w));
    }

    int s;
    cin >> s;

    dijkstra(s);

    int t;
    cin >> t;

    while (t--)
    {
        ll w, dw;
        cin >> w >> dw;

        if (dis[w] <= dw)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
