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

Node *deleteNode(Node *head, int index)
{
    if (head == NULL)
    {
        return head;
    }

    if (index < 0)
    {
        return head;
    }

    if (index == 0)
    {
        return head->next;
    }

    Node *prev = deleteNode(head->next, index - 1);

    head->next = prev;

    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = takeInput();

    int index;
    cin >> index;
    head = deleteNode(head, index);

    printLL(head);

    return 0;
}