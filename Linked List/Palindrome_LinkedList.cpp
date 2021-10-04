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
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }

    return counter;
}

Node *reverseLL(Node *curr, Node *prev)
{
    if (curr->next == NULL)
    {
        curr->next = prev;
        return curr;
    }

    Node *returnNode = reverseLL(curr->next, curr);

    curr->next = prev;

    return returnNode;
}

bool palindrome(Node *head, int len)
{
    if (len == 0 || len == 1)
    {
        return true;
    }

    Node *temp = head;
    Node *temp2 = NULL;
    int mid = len / 2;

    for (int i = 0; i < mid - 1; i++)
    {
        head = head->next;
    }
    temp2 = head->next;
    head->next = NULL;

    temp2 = reverseLL(temp2, NULL);

    while (temp != NULL && temp2 != NULL)
    {
        if (temp->data != temp2->data)
            return false;

        temp = temp->next;
        temp2 = temp2->next;
    }

    return true;
}

int main()
{
    Node *head = takeInput();

    int len = lengthLL(head);

    bool flag = palindrome(head, len);

    if (flag)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}