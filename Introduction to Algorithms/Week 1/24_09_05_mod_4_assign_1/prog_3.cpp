//--> Can Go?

#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool vis[1001][1001];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || (a[i][j] != '.' && a[i][j] != 'B'))
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            dfs(ci, cj);
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
            cin >> a[i][j];

            if (a[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    dfs(si, sj);

    if (vis[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
