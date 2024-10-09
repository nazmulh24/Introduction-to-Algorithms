//--> 2. Convert the graph to Adjacency List and Adjacency Matrix.

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

    vector<int> matt[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1; //--> 1 way direction

        matt[a].push_back(b);
    }

    int x;
    cout << "Enter Node : ";
    cin >> x;

    cout << "Adjacency List : ";
    for (int i = 0; i < matt[x].size(); i++)
    {
        cout << matt[x][i] << " ";
    }

    cout << endl
         << endl
         << "Adjacency Matrix :" << endl;
    print(mat, n);

    return 0;
}
