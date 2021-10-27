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
class Stack
{
    Node<T> *head;
    int size_s;

public:
    Stack()
    {
        head = NULL;
        size_s = 0;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        newNode->next = head;
        head = newNode;
        size_s++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size_s--;
        }
    }

    T top()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            return head->data;
        }
    }

    int size()
    {
        return size_s;
    }

    bool empty()
    {
        return size_s == 0;
    }
};

int main()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    s.push('f');

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.empty() << endl;

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.empty() << endl;

    s.pop();
    cout << s.top() << endl;

    return 0;
}