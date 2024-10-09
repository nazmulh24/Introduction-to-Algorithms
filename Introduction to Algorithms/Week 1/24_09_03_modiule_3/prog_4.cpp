//--> Components

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; //--> 1,00,000+5

vector<int> v[N];
bool vis[N];

void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;

    for (auto child : v[src])
    {
        if (vis[child] == false)
            dfs(child);
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

    memset(vis, false, sizeof(vis));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
            cnt++;
        }
    }

    cout << endl
         << "Component - " << cnt << endl;

    return 0;
}
