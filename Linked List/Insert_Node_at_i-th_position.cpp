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

void PrintLinkedList(Node *head)
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

    int num, index;
    cin >> num >> index;

    int i = 0;
    Node *temp = head;
    Node *newNode = new Node(num);

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        temp = NULL;
    }
    while (temp != NULL && i < index - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp != NULL)
    {
        Node *temp_add = temp->next;
        temp->next = newNode;
        newNode->next = temp_add;
    }

    PrintLinkedList(head);

    return 0;
}