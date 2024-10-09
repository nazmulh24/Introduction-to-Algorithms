//--> CSES - Message Route
//--> https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int parent[N];

int n, m;

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    vis[src] = true;
    parent[src] = -1; // Starting node has no parent

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : adj[node])
        {
            if (!vis[child])
            {
                q.push(child);

                vis[child] = true;
                parent[child] = node;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    bfs(1);

    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    for (int i = n; i != -1; i = parent[i])
        path.push_back(i);

    reverse(path.begin(), path.end());

    cout << path.size() << endl;

    for (auto u : path)
        cout << u << " ";
    cout << endl;

    return 0;
}
