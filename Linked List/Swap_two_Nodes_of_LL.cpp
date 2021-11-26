#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

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

Node *swapNodes(Node *head, int a, int b)
{
    int maxAB = (a > b) ? a : b;
    Node *temp = head;

    int i = 0;

    Node *prev1 = NULL;
    Node *curr1 = NULL;

    Node *prev2 = NULL;
    Node *curr2 = NULL;

    Node *prev = NULL;
    Node *curr = head;

    while (i <= maxAB && temp != NULL)
    {
        if (a == i)
        {
            prev1 = prev;
            curr1 = curr;
        }

        if (b == i)
        {
            prev2 = prev;
            curr2 = curr;
        }

        prev = curr;
        curr = curr->next;
        i++;
        temp = temp->next;
    }

    if (curr1 == NULL || curr2 == NULL)
    {
        cout << "Invalid Indexes" << endl;
        return head;
    }

    bool anyHead = false;

    if (curr1 == head || curr2 == head)
        anyHead = true;

    if (curr2 == head)
    {
        Node *tempPrev = prev2;
        Node *tempCurr = curr2;

        curr2 = curr1;
        prev2 = prev1;

        curr1 = tempCurr;
        prev1 = tempPrev;
    }

    if (!anyHead)
        prev1->next = curr2;

    prev2->next = curr1;
    temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;

    if (anyHead)
        head = curr2;

    return head;
}

int main()
{
    Node *head = takeInput();

    int a, b;
    cin >> a >> b;

    cout << "Linked List Before: " << endl;
    printLL(head);

    if (a != b && head != NULL)
        head = swapNodes(head, a, b);

    cout << "Linked List After: " << endl;
    printLL(head);

    return 0;
}