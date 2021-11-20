#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

struct Node_Pair
{
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
};

BinaryTreeNode<int> *takeInput()
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int> *> q;

    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *curr = q.front();
        q.pop();

        int leftChildData, rightChildData;
        cin >> leftChildData >> rightChildData;

        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            curr->left = leftChild;
            q.push(curr->left);
        }
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            curr->right = rightChild;
            q.push(curr->right);
        }
    }

    return root;
}

Node_Pair BST_to_LL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {NULL, NULL};

    Node<int> *newNode = new Node<int>(root->data);

    Node_Pair leftPart = BST_to_LL(root->left);

    Node_Pair rightPart = BST_to_LL(root->right);

    if (leftPart.head == NULL)
    {
        leftPart.head = newNode;
        leftPart.tail = newNode;
    }
    else
    {
        leftPart.tail->next = newNode;
    }

    if (rightPart.head == NULL)
    {
        rightPart.head = newNode;
        rightPart.tail = newNode;
    }
    else
    {
        newNode->next = rightPart.head;
    }

    return {leftPart.head, rightPart.tail};
}

void printLL(Node<int> *head)
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

    Node_Pair head = BST_to_LL(root);

    printLL(head.head);

    return 0;
}