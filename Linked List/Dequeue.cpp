#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        prev = next = NULL;
    }
};

template <typename T>
class Dequeue
{
    int len;
    Node<T> *head;
    Node<T> *tail;

public:
    Dequeue()
    {
        len = 0;
        head = tail = NULL;
    }

    bool empty()
    {
        return len == 0;
    }

    int size()
    {
        return len;
    }

    void insertFront(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;

            head = newNode;
        }
        len++;
    }

    void insertLast(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;

            tail = newNode;
        }
        len++;
    }

    void deleteFront()
    {
        if (empty())
        {
            cout << "DeQueue Empty" << endl;
            return;
        }

        Node<T> *temp = head;

        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        len--;
    }

    void deleteLast()
    {
        if (empty())
        {
            cout << "DeQueue Empty" << endl;
            return;
        }

        Node<T> *temp = tail;

        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
        len--;
    }

    T getFront()
    {
        if (empty())
        {
            cout << "Dequeue Empty" << endl;
            return 0;
        }

        return head->data;
    }

    T getLast()
    {
        if (empty())
        {
            cout << "Dequeue Empty" << endl;
            return 0;
        }

        return tail->data;
    }
};

int main()
{

    return 0;
}