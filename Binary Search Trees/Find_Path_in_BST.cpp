#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
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

void printLL(Node<int> *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node<int> *findPath(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == k)
    {
        Node<int> *newNode = new Node<int>(root->data);
        return newNode;
    }

    Node<int> *ansLeft = findPath(root->left, k);

    if (ansLeft != NULL)
    {
        Node<int> *newNode = new Node<int>(root->data);
        newNode->next = ansLeft;
        return newNode;
    }

    Node<int> *ansRight = findPath(root->right, k);

    if (ansRight != NULL)
    {
        Node<int> *newNode = new Node<int>(root->data);
        newNode->next = ansRight;
        return newNode;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    int k;
    cin >> k;

    Node<int> *ans = findPath(root, k);

    printLL(ans);

    return 0;
}