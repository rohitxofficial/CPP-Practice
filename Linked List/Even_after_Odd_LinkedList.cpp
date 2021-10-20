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

Node *evenOdd(Node *head)
{
    Node *firstOdd = NULL;
    Node *lastOdd = NULL;
    Node *firstEven = NULL;
    Node *lastEven = NULL;

    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (firstEven == NULL)
            {
                firstEven = head;
                lastEven = head;
            }
            else
            {
                lastEven->next = head;
                lastEven = head;
            }
        }
        else
        {
            if (firstOdd == NULL)
            {
                firstOdd = head;
                lastOdd = head;
            }
            else
            {
                lastOdd->next = head;
                lastOdd = head;
            }
        }
        head = head->next;
    }

    if (firstEven == NULL && firstOdd == NULL)
    {
        return head;
    }
    else if (firstEven == NULL)
    {
        lastOdd->next = NULL;
        return firstOdd;
    }
    else if (firstOdd == NULL)
    {
        lastEven->next = NULL;
        return firstEven;
    }
    else
    {
        lastOdd->next = NULL;
        lastEven->next = NULL;
        lastOdd->next = firstEven;
        return firstOdd;
    }
}

int main()
{
    Node *head = takeInput();

    head = evenOdd(head);

    printLL(head);

    return 0;
}