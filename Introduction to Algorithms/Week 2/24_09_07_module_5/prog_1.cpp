//--> Cycle Ditection in Undirected Graph using BFS...

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int par[N];
bool ans;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        // cout << parent << endl;

        for (auto child : adj[parent])
        {
            if (vis[child] == true && par[parent] != child)
            {
                ans = true;
            }

            if (!vis[child])
            {
                vis[child] = true;
                par[child] = parent;
                q.push(child);
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    if (ans)
        cout << "Cycle Ase..." << endl;
    else
        cout << "Cycle Nai..." << endl;

    return 0;
}
