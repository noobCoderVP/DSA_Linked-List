//= Question: Reverse the linked list recursively represented by the input

//= Input
// 4
// 1 2 3 4

//= Output
// 4 3 2 1

#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

void printReverse(Node *node)
{
    if (node == NULL)
        return;

    printReverse(node->next);
    cout << node->data << " => ";
}

void printRecursiveSTL(list<int> l)
{
    // base condition
    if (l.empty())
    {
        return;
    }

    // do something
    cout << l.back() << " => ";

    // reduce the size
    l.pop_back();
    printRecursiveSTL(l);
}

int main()
{
    LinkedList classical;
    for (int i = 1; i < 5; i++)
    {
        classical.push(i);
    }

    list<int> STLlist{1, 2, 3, 4};

    printReverse(classical.Head);
    cout << endl;

    printRecursiveSTL(STLlist);
    cout << endl;
}