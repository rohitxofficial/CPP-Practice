#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput()
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
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

        cin >> data;
    }

    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseLL(Node *first, Node *last)
{
    Node *prev = last;

    while (first != last)
    {
        Node *temp = first->next;
        first->next = prev;
        prev = first;
        first = temp;
    }

    return prev;
}

Node *kReverse(Node *head, int k)
{
    Node *tail = head;
    for (int i = 0; i < k; ++i)
    {
        if (tail == NULL)
            return head;
        tail = tail->next;
    }

    Node *newHead = reverseLL(head, tail);

    head->next = kReverse(tail, k);

    return newHead;
}

int main()
{
    Node *head = takeInput();
    int k;
    cin >> k;

    if (k != 0 && k != 1)
    {
        head = kReverse(head, k);
    }

    printLinkedList(head);

    return 0;
}