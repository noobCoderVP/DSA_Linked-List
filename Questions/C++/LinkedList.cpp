#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *Head;
    int size;

    LinkedList()
    {
        Head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    void push(int element)
    {
        Node *test = Head;

        // creating a new node with the data element
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;

        if (Head == NULL)
        {

            // Head will point towards first node
            Head = newNode;

            size++;
            return;
        }

        while (test->next != NULL)
        {
            test = test->next;
        }

        // adding the new node at the end
        test->next = newNode;

        size++; //! bhulna mat
    }

    void pop()
    {
        if (Head == NULL)
        {
            cout << "cannot pop, Linked list is empty!" << endl;
            return; //! bhulna mat
        }

        Node *test = Head;

        if (test->next == NULL)
        {
            Head = NULL;
            return;
        }

        while (test->next->next != NULL)
        {
            test = test->next;
        }

        // storing the node to be deleted
        Node *toBeDeleted = test->next;

        test->next = NULL;

        delete toBeDeleted;
        size--;
    }

    void insertAfter(Node *node, int elem)
    {
        Node *test = Head;

        while (test != NULL and test != node)
        {
            test = test->next;
        }

        if (test == NULL)
            return;

        // connecting the new node
        Node *newNode = new Node;
        newNode->data = elem;
        newNode->next = test->next;

        // changing the next link of the given node to the new node
        test->next = newNode;

        size++;
    }

    void del(Node *node)
    {
        if (size == 0)
        {
            cout << "Linked List is already empty!!" << endl;
            return;
        }

        // 1 => 2 => 4 => 9 => NULL
        // NOTE: if i have to delete node with data = 4, i will have to reach node just before it (2), because we have to change the link of previous node to the next node of the node being deleted and in singly linked list we cannot go backwards.

        Node *test = Head;

        while (test->next != NULL and test->next != node)
        {
            test = test->next;
        }

        if (test->next == NULL)
            return;

        // do step 1: store the node which has to be deleted
        Node *toBeDeleted = test->next;

        // do step 2: change the link of previous node of the node being deleted
        test->next = test->next->next;

        // do step 3: delete the stored node
        delete toBeDeleted;
    }

    void print()
    {
        Node *test = Head;
        if (!Head)
        {
            cout << "Linked list is empty!!" << endl;
        }

        // print the first element
        cout << test->data;

        // print other elements with chain
        while (test->next != NULL)
        {
            test = test->next;
            cout << " => " << test->data;
        }
        cout << endl;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Linked list is empty!!" << endl;
            return INT16_MAX; // garbage value is returned
        }
        cout << Head->data << endl;
    }

    int back()
    {
        if (size == 0)
        {
            cout << "Linked list is empty!!" << endl;
            return INT16_MAX; // garbaage value is returned
        }

        Node *test = Head;
        while (test->next != NULL)
        {
            test = test->next;
        }
        return test->data;
    }
};

//! driver code for testing
// int main()
// {
//     LinkedList l;

//     for (int i = 1; i < 10; i++)
//     {
//         l.push(i);
//     }

//     cout << l.size << endl;
//     l.print();

//     l.pop();
//     l.print();

//     l.insertAfter(l.Head->next, 20);
//     l.print();

//     l.del(l.Head->next);
//     l.print();

//     cout << l.isEmpty() << endl;
// }