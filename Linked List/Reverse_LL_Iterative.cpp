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

int main()
{
    Node *head = takeInput();

    head = reverseLL(head);

    printLinkedList(head);

    return 0;
}