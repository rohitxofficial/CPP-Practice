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

int elementAtI(Node *head, int x)
{
    Node *temp = head;

    int count = 0;
    while (temp != NULL)
    {
        if (count == x)
            return temp->data;

        temp = temp->next;
        count++;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t > 0)
    {
        Node *head = takeInput();
        int x;
        cin >> x;

        cout << elementAtI(head, x) << endl;

        t--;
    }

    return 0;
}