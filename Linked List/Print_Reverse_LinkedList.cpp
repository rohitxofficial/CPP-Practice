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

void printReverseLL(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    printReverseLL(head->next);

    cout << head->data << " ";
}

int main()
{
    Node *head = takeInput();

    printReverseLL(head);

    return 0;
}