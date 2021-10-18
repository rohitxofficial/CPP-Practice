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
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    Node *head = NULL;
    Node *tail = NULL;

    if (head1 != NULL)
    {
        if (head2 != NULL)
        {
            if (head1->data > head2->data)
            {
                head = head2;
                tail = head2;
                head2 = head2->next;
            }
            else
            {
                head = head1;
                tail = head1;
                head1 = head1->next;
            }
        }
        else
        {
            head = head1;
            tail = head1;
            head1 = head1->next;
        }
    }
    else if (head2 != NULL)
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    else
    {
        return 0;
    }

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 == NULL)
        {
            tail->next = head2;
            break;
        }
        else if (head2 == NULL)
        {
            tail->next = head1;
            break;
        }
        else
        {
            if (head1->data > head2->data)
            {
                tail->next = head2;
                tail = head2;

                head2 = head2->next;
            }
            else
            {
                tail->next = head1;
                tail = head1;

                head1 = head1->next;
            }
        }
    }

    printLL(head);

    return 0;
}
