//--> Adjacency Matrix

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
    int n; //--> node
    cin >> n;

    int e; //--> edge
    cin >> e;

    int mat[1000][1000];
    memset(mat, 0, sizeof(mat)); //--> matrix 0 diye initialize kore...

    print(mat, n);

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    cout << endl;
    print(mat, n);

    if (mat[3][1] == 1)
        cout << "Connection Ase..." << endl;
    else
        cout << "Connection Nai" << endl;

    return 0;
}
