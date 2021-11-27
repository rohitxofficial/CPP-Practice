#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
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

BinaryTreeNode<int> *takeInput()
{
    int data;
    cin >> data;

    queue<BinaryTreeNode<int> *> q;

    BinaryTreeNode<int> *root = NULL;

    if (data != -1)
    {
        root = new BinaryTreeNode<int>(data);
        q.push(root);
    }

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        int leftData, rightData;

        cin >> leftData >> rightData;

        BinaryTreeNode<int> *left = NULL, *right = NULL;

        if (leftData != -1)
        {
            left = new BinaryTreeNode<int>(leftData);
            q.push(left);
        }
        if (rightData != -1)
        {
            right = new BinaryTreeNode<int>(rightData);
            q.push(right);
        }

        front->left = left;
        front->right = right;
    }

    return root;
}

vector<Node *> levelWiseLinkedList(BinaryTreeNode<int> *root)
{
    vector<Node *> arr;

    if (root == NULL)
        return arr;

    queue<BinaryTreeNode<int> *> q;

    q.push(root);
    q.push(NULL);

    Node *head = NULL;
    Node *tail = NULL;

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front == NULL)
        {
            if (!q.empty())
                q.push(NULL);
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *newNode = new Node(front->data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                arr.push_back(head);
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }
    }
    return arr;
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
    BinaryTreeNode<int> *root = takeInput();

    vector<Node *> arr = levelWiseLinkedList(root);

    for (int i = 0; i < arr.size(); i++)
    {
        printLL(arr[i]);
    }

    return 0;
}