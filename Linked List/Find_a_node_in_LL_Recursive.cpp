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

int findNode(Node *head, int x)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->data == x)
        return 0;

    int final_index = findNode(head->next, x);

    if (final_index == -1)
        return -1;
    else
        return final_index + 1;
}

int main()
{
    Node *head = takeInput();

    int x;
    cin >> x;

    cout << findNode(head, x) << endl;

    return 0;
}