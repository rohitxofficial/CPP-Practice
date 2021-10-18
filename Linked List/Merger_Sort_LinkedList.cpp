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

Node *mergeLinkedList(Node *head1, Node *head2)
{
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
    return head;
}

Node *sort(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *p1 = head;
    Node *p2 = head->next;

    while (p2 != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    Node *head2 = p1->next;
    p1->next = NULL;
    Node *sorted_head1 = sort(head);
    Node *sorted_head2 = sort(head2);

    Node *mergerd_head = mergeLinkedList(sorted_head1, sorted_head2);

    return mergerd_head;
}

int main()
{
    Node *head = takeInput();

    head = sort(head);

    printLL(head);

    return 0;
}