#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

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

void printNodesDepth(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
        return;

    if (k == 0)
        cout << root->data << endl;

    printNodesDepth(root->left, k - 1);
    printNodesDepth(root->right, k - 1);
}

int printNodes(BinaryTreeNode<int> *root, int n, int k)
{
    if (root == NULL)
        return -1;

    if (root->data == n)
    {
        printNodesDepth(root, k);
        return 1;
    }

    int leftDepth = printNodes(root->left, n, k);

    if (leftDepth != -1)
    {
        if (k - leftDepth == 0)
        {
            cout << root->data << endl;
            return leftDepth + 1;
        }
        if (k - leftDepth > 0)
        {
            printNodesDepth(root->right, k - leftDepth - 1);
            return leftDepth + 1;
        }
    }

    int rightDepth = printNodes(root->right, n, k);

    if (rightDepth != -1)
    {
        if (k - rightDepth == 0)
        {
            cout << root->data << endl;
            return rightDepth + 1;
        }
        if (k - rightDepth > 0)
        {
            printNodesDepth(root->left, k - rightDepth - 1);
            return rightDepth + 1;
        }
    }

    return -1;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int n, k;
    cin >> n >> k;

    printNodes(root, n, k);

    return 0;
}