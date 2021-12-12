#include <vector>
#include <iostream>
using namespace std;

class MaxPriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getsize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }

    void printPriorityQueue()
    {
        int len = pq.size();

        for (int i = 0; i < len; i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;

        while (pq[childIndex] > pq[parentIndex] && childIndex != 0)
        {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    void removeMax()
    {
        if (isEmpty())
            return;

        int firstIndex = pq[0];
        int lastIndex = pq.size() - 1;

        int temp = pq[firstIndex];
        pq[firstIndex] = pq[lastIndex];
        pq[lastIndex] = temp;

        pq.pop_back();

        int parentIndex = 0;
        int child1 = 2 * parentIndex + 1;
        int child2 = 2 * parentIndex + 2;
        while (child1 < pq.size())
        {
            if (child2 >= pq.size() && pq[parentIndex] < pq[child1])
            {
                int temp2 = pq[parentIndex];
                pq[parentIndex] = pq[child1];
                pq[child1] = temp2;

                break;
            }
            else if (pq[parentIndex] > pq[child1] && pq[parentIndex] > pq[child2])
            {
                break;
            }
            else
            {
                int maxIndex = (pq[child1] < pq[child2]) ? child2 : child1;

                int temp2 = pq[parentIndex];
                pq[parentIndex] = pq[maxIndex];
                pq[maxIndex] = temp2;

                parentIndex = maxIndex;
                child1 = 2 * parentIndex + 1;
                child2 = 2 * parentIndex + 2;
            }
        }
    }
};
