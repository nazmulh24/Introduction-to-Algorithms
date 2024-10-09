//--> STL Pair

#include <bits/stdc++.h>
using namespace std;

// class Pair
// {
// public:
//     int first, second;
//     void make_pair(int a, int b)
//     {
//         first = a;
//         second = b;
//     }
// };

//|||||||||--> Build_in -->> pair<int, int> p

int main()
{
    // Pair p;
    // p.first = 10;
    // p.second = 20;

    // p.make_pair(10, 20);

    //-----------------------------------------------

    pair<int, int> p;

    p = make_pair(10, 20);

    cout << p.first << " " << p.second << endl;

    return 0;
}
