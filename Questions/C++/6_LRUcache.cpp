#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    // store keys of cache
    list<int> dq;

    // store references of key in cache
    unordered_map<int, list<int>::iterator> m;
    int cacheSize; // maximum capacity of cache

    LRUCache(int n)
    {
        cacheSize = n;
    };

    void refer(int x)
    {
        // not present in cache
        if (m.find(x) == m.end())
        {
            // cache is full
            if (dq.size() == cacheSize)
            {
                // delete least recently used element
                int last = dq.back();

                // Pops the last element
                dq.pop_back();

                // Erase the last
                m.erase(last);
            }
        }

        // present in cache
        else
            dq.erase(m[x]);

        // update reference
        dq.push_front(x);
        m[x] = dq.begin();
    };

    void display()
    {
        for (auto it = dq.begin(); it != dq.end(); it++)
            cout << (*it) << " ";

        cout << endl;
    };
};

// Driver Code
int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}