//--> Shortest Distance

#include <bits/stdc++.h>
#define ll long long int
#define INF 10e15
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    ll adj[n][n];

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            adj[i][j] = INF;

            if (i == j)
                adj[i][j] = 0;
        }
    }

    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;

        adj[a][b] = min(adj[a][b], w);
    }

    for (ll k = 0; k < n; k++)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (adj[x][y] == INF)
            cout << "-1" << endl;
        else
            cout << adj[x][y] << endl;
    }

    return 0;
}
