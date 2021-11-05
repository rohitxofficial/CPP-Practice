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
        cout << head->data;
        head = head->next;
    }
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    if (head != NULL)
        next = head->next;

    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;

        if (next != NULL)
        {
            next = next->next;
        }
    }

    return prev;
}

Node *addOne(Node *head)
{
    Node *tempHead = head;

    int carry = 1;
    while (tempHead != NULL)
    {
        tempHead->data += carry;

        if (tempHead->data == 10)
        {
            carry = 1;
            tempHead->data = 0;
        }
        else
        {
            carry = 0;
        }
        tempHead = tempHead->next;
    }

    head = reverseLL(head);

    if (carry == 1)
    {
        Node *newNode = new Node(1);

        newNode->next = head;
        head = newNode;
    }

    return head;
}

int main()
{
    Node *head = takeInput();

    head = reverseLL(head);

    head = addOne(head);

    printLL(head);

    return 0;
}