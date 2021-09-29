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

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *deleteNode(Node *head, int index)
{
    int i = 0;
    Node *temp = head;

    if (index < 0)
    {
        return head;
    }

    if (index == 0)
    {
        return temp->next;
    }

    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp != NULL)
    {
        Node *temp2 = temp->next;
        if (temp2 != NULL)
            temp->next = temp2->next;
    }

    return head;
}

int main()
{
    Node *head = takeInput();
    int index;
    cin >> index;
    head = deleteNode(head, index);
    printLinkedList(head);
    return 0;
}