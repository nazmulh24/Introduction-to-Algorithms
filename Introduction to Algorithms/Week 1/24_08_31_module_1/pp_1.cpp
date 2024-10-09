//--> 1. Convert the graph to an Adjacency matrix.

#include <bits/stdc++.h>
using namespace std;

void print(int mat[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    int mat[1000][1000];
    memset(mat, 0, sizeof(mat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    print(mat, n);

    return 0;
}
