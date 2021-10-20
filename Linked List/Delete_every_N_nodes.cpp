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

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = takeInput();

    int n, m;
    cin >> n >> m;

    if (n == 0)
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        return 0;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        for (int i = 0; i < n && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        Node *temp2;
        for (int i = 0; i < m && temp != NULL; i++)
        {
            temp2 = temp->next;
            delete temp;
            temp = temp2;
        }

        if (prev != NULL)
            prev->next = temp;
    }

    printLL(head);

    return 0;
}