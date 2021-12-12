#include <vector>
#include <iostream>
using namespace std;

class MinPriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (pq.size() != 0)
            return pq[0];
        else
            return 0;
    }

    void printPriorityQueue()
    {
        int pqSize = pq.size();
        for (int i = 0; i < pqSize; i++)
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

        while (pq[childIndex] < pq[parentIndex] && childIndex != 0)
        {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    void removeMin()
    {
        if (isEmpty())
            return;

        int firstIndex = 0;
        int lastIndex = pq.size() - 1;

        if (pq.size() > 1)
        {
            int temp = pq[firstIndex];
            pq[firstIndex] = pq[lastIndex];
            pq[lastIndex] = temp;
        }

        pq.pop_back();

        int parentIndex = 0;
        int child1 = 2 * parentIndex + 1;
        int child2 = 2 * parentIndex + 2;

        while (child1 < pq.size())
        {
            if (child2 >= pq.size())
            {
                if (pq[parentIndex] > pq[child1])
                {
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[child1];
                    pq[child1] = temp;

                    parentIndex = child1;
                    child1 = 2 * parentIndex + 1;
                    child2 = 2 * parentIndex + 2;

                    break;
                }
            }
            else if (pq[parentIndex] < pq[child1] && pq[parentIndex] < pq[child2])
            {
                break;
            }
            else
            {
                int minElementIndex = (pq[child1] < pq[child2]) ? child1 : child2;

                int temp = pq[parentIndex];
                pq[parentIndex] = pq[minElementIndex];
                pq[minElementIndex] = temp;

                parentIndex = minElementIndex;
                child1 = 2 * parentIndex + 1;
                child2 = 2 * parentIndex + 2;
            }
        }
    }
};
