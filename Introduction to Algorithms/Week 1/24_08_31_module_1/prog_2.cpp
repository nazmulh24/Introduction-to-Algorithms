//--> Adjacency List

#include <bits/stdc++.h>
using namespace std;

vector<int> mat[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    for (int i = 0; i < mat[0].size(); i++)
        cout << mat[0][i] << " ";

    return 0;
}
