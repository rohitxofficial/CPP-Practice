#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    int LL_size;
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        LL_size = 0;
        head = NULL;
        tail = NULL;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        LL_size++;
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue Empty" << endl;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;

            delete temp;
            LL_size--;
        }
    }

    T front()
    {
        if (empty())
        {
            cout << "Queue Empty" << endl;
            return 0;
        }
        return head->data;
    }

    int size()
    {
        return LL_size;
    }

    bool empty()
    {
        return LL_size == 0;
    }
};

int main()
{

    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;

    cout << q.size() << endl;
    cout << q.empty() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.empty() << endl;
    return 0;
}
