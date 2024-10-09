//--> CSES - Labyrinth
//--> https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

char grid[N][N];
bool vis[N][N];
int dis[N][N];
pair<int, int> parent[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();

        // cout << a << " " << b << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {make_pair(a, b)};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    if (vis[di][dj])
    {
        cout << "YES" << endl;
        cout << dis[di][dj] << endl;

        //-------------------------------------------
        pair<int, int> p = {di, dj};
        vector<pair<int, int>> path;

        while (!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }
        path.push_back({si, sj});

        reverse(path.begin(), path.end());

        string ans = "";

        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first) //--> L/R
            {
                if (path[i - 1].second + 1 == path[i].second)
                    ans += "R";
                else
                    ans += "L";
            }
            else //--> U/D
            {
                if (path[i - 1].first + 1 == path[i].first)
                    ans += "D";
                else
                    ans += "U";
            }
        }
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
