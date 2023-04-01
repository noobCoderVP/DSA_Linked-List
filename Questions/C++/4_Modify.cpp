#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

class modifiedLL : public LinkedList
{
public:
    void juggle()
    {
        Node *secondNode = Head->next;
        Node *thirdNode = Head->next->next;

        secondNode->next = Head;
        Head->next = thirdNode;
        Head = secondNode;

        Node *test = Head->next; // 2

        // 1 => 2 => 3 => 4 => NULL
        while (test->next != NULL) // true for NULL
        {
            Node *firstNode = test->next; // 3
            Node *secondNode = test->next->next; // 4
            Node *thirdNode = test->next->next->next; // NULL

            secondNode->next = firstNode;
            firstNode->next = thirdNode;
            test->next = secondNode;

//             incrementing test
            test = test->next->next; // 4
        }
    }
};

int main()
{
    modifiedLL classical;
    for (int i = 1; i < 5; i++)
    {
        classical.push(i);
    }

    classical.print();
    classical.juggle();
    classical.print();
}
