#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *data;
    int lastIndex;
    int firstIndex;
    int data_size;
    int capacity;

public:
    Queue(int array_size)
    {
        data = new T[array_size];
        firstIndex = -1;
        lastIndex = 0;
        data_size = 0;
        capacity = array_size;
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
            cout << "Queue Full" << endl;
            return;
        }

        data[lastIndex] = element;
        lastIndex = (lastIndex + 1) % capacity;
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
            lastIndex = 0;
        }
    }
};

int main()
{
    Queue<char> q(5);

    return 0;
}