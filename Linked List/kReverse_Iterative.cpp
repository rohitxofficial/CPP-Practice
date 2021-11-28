#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

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

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse(Node *&head, Node *&tail)
{
    Node *breakPoint = tail->next;

    Node *prev = NULL;
    Node *curr = head;
    Node *next = head->next;

    while (curr != breakPoint)
    {
        curr->next = prev;
        prev = curr;
        curr = next;

        if (next != NULL)
            next = next->next;
    }
}

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    Node *newHead = NULL;

    Node *tail = head;
    Node *prev = NULL;
    Node *next = tail->next;

    while (head != NULL)
    {
        int i = 1;
        while (i < k && tail->next != NULL)
        {
            tail = tail->next;
            if (next != NULL)
                next = tail->next;
            i++;
        }

        reverse(head, tail);

        if (newHead == NULL)
        {
            newHead = tail;
            head->next = next;
        }
        else
        {
            prev->next = tail;
            head->next = next;
        }

        prev = head;
        head = next;
        tail = next;
        if (tail != NULL)
            next = tail->next;
    }

    return newHead;
}

int main()
{
    Node *head = takeInput();

    int k;
    cin >> k;

    head = kReverse(head, k);

    printLL(head);

    return 0;
}