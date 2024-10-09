//--> Detect Negative Cycle using Bellman Ford

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edgeList.push_back(Edge(a, b, c)); //--> direct graph...
        // edgeList.push_back(Edge(b, a, c)); //--> undirect graph...
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edgeList)
        {
            // cout << ed.u << " " << ed.v << " " << ed.c << endl;

            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }

    bool cycle = false;

    for (auto ed : edgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
            dis[v] = dis[u] + c;
        }
    }

    if (cycle)
        cout << "No answer..." << endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}
