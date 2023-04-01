//= Question: Given an array of length n, print distinct elements in sorted order.

//* Example

//= Input
// 6
// 2 4 3 3 2 1

//= Output
// 1 2 3 4

//! This question can be solved easily using the inbuilt template class list of C++

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int test;

    list<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> test;
        arr.push_back(test);
    }

    //! Alternative
    // vector <int> vec(n);
    // for(int i = 0; i < n; i++)
    // {
    //       cin >> vec[i];
    // }
    // list <int> arr(vec.begin(), vec.end()); //! used in most cases

    arr.sort();
    arr.unique();

    while (!arr.empty())
    {
        cout << arr.front() << " ";
        arr.pop_front();
    }
    cout << endl;
}