#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

bool detectLoop(Node *head)
{
    Node *slow = head,
         *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        // change pointers
        slow = slow->next;
        fast = fast->next->next;

        // check if both pointers are equal
        if (slow == fast)
            return 1;
    }

    return 0;
}

int main()
{
    LinkedList looped;
    LinkedList normal;

    for (int i = 1; i < 10; i++)
    {
        looped.push(i);
        normal.push(i);
    }

    Node *linkedNode = looped.Head->next->next;

    Node *test = looped.Head;
    // creating a cycle
    while (test->next != NULL)
    {
        test = test->next;
    }
    test->next = linkedNode;

    cout << detectLoop(normal.Head) << endl; // will give output as 0
    cout << detectLoop(looped.Head) << endl; // will give output as 1
}