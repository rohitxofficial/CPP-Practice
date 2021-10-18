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

int main()
{
    Node *head = takeInput();

    if (head == NULL)
    {
        return 0;
    }

    Node *p1 = head;
    Node *p2 = head->next;

    while (p2 != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    cout << p1->data << endl;

    return 0;
}