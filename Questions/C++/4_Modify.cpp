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

        Node *test = Head->next;

        while (test->next != NULL)
        {
            Node *firstNode = test->next;
            Node *secondNode = test->next->next;
            Node *thirdNode = test->next->next->next;

            secondNode->next = firstNode;
            firstNode->next = thirdNode;
            test->next = secondNode;

            test = test->next->next;
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