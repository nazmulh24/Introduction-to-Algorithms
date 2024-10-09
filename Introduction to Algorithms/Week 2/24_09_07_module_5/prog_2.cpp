//--> Cycle Ditection in Undirected Graph using DFS...

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int par[N];
bool ans;

void dfs(int parent)
{
    vis[parent] = true;

    cout << parent << endl;

    for (auto child : adj[parent])
    {
        if (vis[child] == true && par[parent] != child)
        {
            ans = true;
        }

        if (vis[child] == false)
        {
            par[child] = parent;
            dfs(child);
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
            dfs(i);
        }
    }
    if (ans)
        cout << "Cycle Ase..." << endl;
    else
        cout << "Cycle Nai..." << endl;

    return 0;
}
