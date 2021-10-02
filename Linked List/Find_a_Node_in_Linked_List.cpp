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

int findNode(Node *head, int element)
{
    Node *temp = head;

    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }

    return -1;
}

int main()
{
    Node *head = takeInput();
    int element;
    cin >> element;

    cout << findNode(head, element) << endl;

    return 0;
}