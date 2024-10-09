//--> Count Apartments II

#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool vis[1001][1001];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] != '.')
        return false;
    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int r_size = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) == true && vis[ci][cj] == false)
        {
            r_size += dfs(ci, cj);
        }
    }
    return r_size;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && vis[i][j] == false)
            {
                int s = dfs(i, j);
                v.push_back(s);
            }
        }
    }

    sort(v.begin(), v.end());

    if (v.empty())
        cout << 0 << endl;
    else
    {
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }

    return 0;
}
