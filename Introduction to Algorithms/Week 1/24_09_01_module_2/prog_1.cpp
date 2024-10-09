//--> BFS Traversal Implementation

#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005]; //--> 2D Array...
bool vis[1005];      //--> visit array - Track rakhar jonno...

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << " ";

        // for (int i = 0; i < v[par].size(); i++)
        for (auto child : v[par])
        {
            // int child = v[par][i];
            // cout << child << " ";

            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
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

    bfs(src);

    return 0;
}
