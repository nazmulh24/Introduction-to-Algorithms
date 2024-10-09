//--> Knight Moves

#include <bits/stdc++.h>
using namespace std;

bool vis[101][101];
int dis[101][101];

vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        int ki, kj, qi, qj;
        cin >> ki >> kj;

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        bfs(ki, kj);

        cin >> qi >> qj;

        cout << dis[qi][qj] << endl;
    }

    return 0;
}
