#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *curr = pendingNodes.front();
        pendingNodes.pop();

        cout << curr->data << ": ";

        if (curr->left != NULL)
        {
            pendingNodes.push(curr->left);
            cout << "L -> " << curr->left->data << " ";
        }

        if (curr->right != NULL)
        {
            pendingNodes.push(curr->right);
            cout << "R -> " << curr->right->data << " ";
        }

        cout << endl;
    }
}

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

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    printBinaryTree(root);

    delete root;

    return 0;
}