//--> Connected Nodes

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> v[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        sort(v[i].rbegin(), v[i].rend());

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;

        if (v[x].empty())
        {
            cout << "-1" << endl;
            continue;
        }

        for (int i = 0; i < v[x].size(); i++)
        {
            cout << v[x][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
