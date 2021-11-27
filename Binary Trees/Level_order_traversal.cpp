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

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    int level = 0;
    int levelElements = pow(2, level);

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front != NULL)
        {

            cout << front->data << " ";
            levelElements--;

            if (levelElements == 0)
            {
                cout << endl;
                level++;
                levelElements = pow(2, level);
            }

            q.push(front->left);
            q.push(front->right);
        }
        else
        {
            levelElements--;

            if (levelElements == 0)
            {
                cout << endl;
                level++;
                levelElements = pow(2, level);
            }
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    printBinaryTree(root);

    return 0;
}