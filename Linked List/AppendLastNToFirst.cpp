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

int lengthLL(Node *head)
{
    Node *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

Node *appendLastNToFirst(Node *head, int n)
{
    Node *temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }

    Node *temp2 = temp->next;

    temp->next = NULL;

    Node *newHead = temp2;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = head;

    return newHead;
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
    int len = lengthLL(head);

    int n;
    cin >> n;

    if (n > 0 && n < len)
        head = appendLastNToFirst(head, len - n);

    printLL(head);

    return 0;
}