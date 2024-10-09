//--> Dijkstra Optimized Implementation

#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int> > v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    // queue<pair<int, int> > q;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    pq.push(make_pair(src, 0));
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int node = par.first;
        int cost = par.second;

        // for (int i = 0; i < v[node].size(); i++)
        // {
        //     pair<int, int> child = v[node][i];
        // }
        for (pair<int, int> child : v[node])
        {
            int c_node = child.first;
            int c_cost = child.second;

            if (cost + c_cost < dis[c_node])
            {
                //-->path Relaxation...
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

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
        // cout << i << " -> " << dis[i] << endl;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}
