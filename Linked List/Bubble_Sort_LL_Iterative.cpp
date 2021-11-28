#include <bits/stdc++.h>
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

void swap(Node *prev, Node *curr1, Node *curr2)
{
    Node *temp = curr2->next;
    if (prev != NULL)
        prev->next = curr2;
    curr2->next = curr1;
    curr1->next = temp;
}

int lengthLL(Node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        head = head->next;
        ans++;
    }
    return ans;
}

Node *bubbleSort(Node *head)
{
    int length = lengthLL(head);

    for (int i = 0; i < length - 1; i++)
    {
        Node *prev = NULL;
        Node *curr = head;

        for (int j = 0; j < length - 1 - i; j++)
        {
            if (curr->data > curr->next->data)
            {
                Node *curr2 = curr->next;
                swap(prev, curr, curr2);
                if (prev == NULL)
                    head = curr2;

                prev = curr2;
                curr = curr2->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    return head;
}

int main()
{
    Node *head = takeInput();

    head = bubbleSort(head);

    printLL(head);

    return 0;
}