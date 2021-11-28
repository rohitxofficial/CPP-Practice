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

void nodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    if ((root->left == NULL || root->right == NULL) && (root->left != NULL || root->right != NULL))
    {
        if (root->left == NULL)
            cout << root->right->data << " ";
        if (root->right == NULL)
            cout << root->left->data << " ";
    }

    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    nodesWithoutSibling(root);

    return 0;
}