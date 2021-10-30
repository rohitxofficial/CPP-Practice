#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *data;
    int nextIndex;
    int firstIndex;
    int data_size;
    int capacity;

public:
    Queue()
    {
        data = new T[5];
        firstIndex = -1;
        nextIndex = 0;
        data_size = 0;
        capacity = 5;
    }

    T front()
    {
        if (firstIndex != -1)
            return data[firstIndex];
        cout << "Queue Empty!" << endl;
        return 0;
    }

    int size()
    {
        return data_size;
    }

    bool empty()
    {
        return data_size == 0;
    }

    void enqueue(T element)
    {
        if (data_size == capacity)
        {
            T *temp = new T[capacity * 2];

            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                temp[j] = data[i];
                j++;
            }

            for (int i = 0; i < nextIndex; i++)
            {
                temp[j] = data[i];
                j++;
            }

            delete[] data;

            data = temp;

            nextIndex = capacity;
            capacity = capacity * 2;
            firstIndex = 0;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
            firstIndex = 0;

        data_size++;
    }

    void dequeue()
    {
        if (data_size == 0)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        firstIndex = (firstIndex + 1) % capacity;
        data_size--;

        if (data_size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
    }
};

int main()
{
    Queue<char> q;

    return 0;
}