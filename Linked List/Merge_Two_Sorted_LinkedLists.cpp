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

void placeNode(Node *&head, Node *&tail, Node *&head1)
{
    if (head == NULL)
    {
        head = head1;
        tail = head1;
    }
    else
    {
        tail->next = head1;
        tail = head1;
    }
    head1 = head1->next;
}

int main()
{
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 == NULL)
        {
            placeNode(head, tail, head2);
        }
        else if (head2 == NULL)
        {
            placeNode(head, tail, head1);
        }
        else
        {
            if (head1->data > head2->data)
            {
                placeNode(head, tail, head2);
            }
            else
            {
                placeNode(head, tail, head1);
            }
        }
    }

    printLL(head);

    return 0;
}