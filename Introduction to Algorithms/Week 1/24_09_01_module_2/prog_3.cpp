//--> BFS Traversal with Level Pair

#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005]; //--> 2D Array...
bool vis[1005];      //--> visit array - Track rakhar jonno...
// int level[1005];     //--> Level track korbo...

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    bool paisi = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int par = p.first;
        int level = p.second;
        q.pop();

        if (par == des)
        {
            cout << "Total edge count : " << level << endl;
            paisi = false;
        }

        for (auto child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    if (paisi)
        cout << "Total edge count : -1" << endl;
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

    bfs(src, 8);

    return 0;
}
