//--> Path Printing using BFS

#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005]; //--> 2D Array...
bool vis[1005];      //--> visit array - Track rakhar jonno...
int level[1005];     //--> Level track korbo...
int parent[1005];    //--> Parent track korbo...

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin >> src; //--> Jeta root/ source ->level 0

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(src);

    int x;
    cin >> x;

    vector<int> path;

    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }

    reverse(path.begin(), path.end());

    for (auto u : path)
        cout << u << " ";
    cout << endl;

    return 0;
}
