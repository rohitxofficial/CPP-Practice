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

BinaryTreeNode<int> *findLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    if (root->data > a && root->data > b)
    {
        return findLCA(root->left, a, b);
    }
    else if (root->data < a && root->data < b)
    {
        return findLCA(root->right, a, b);
    }
    else
    {
        BinaryTreeNode<int> *left = findLCA(root->left, a, b);
        BinaryTreeNode<int> *right = findLCA(root->right, a, b);

        if (left != NULL && right != NULL)
            return root;
        else if (left != NULL)
            return left;
        else if (right != NULL)
            return right;
        else
            return NULL;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    int a, b;
    cin >> a >> b;

    BinaryTreeNode<int> *lca = findLCA(root, a, b);

    if (lca != NULL)
        cout << lca->data << endl;
    else
        cout << "-1";

    return 0;
}