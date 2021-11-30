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

void checkCousins(BinaryTreeNode<int> *root, int p, int q, BinaryTreeNode<int> *&leftFinal, BinaryTreeNode<int> *&rightFinal, int &leftLevel, int &rightLevel, int level)
{
    if (root == NULL)
        return;

    if (root->data == p)
    {
        leftLevel = level;
        return;
    }

    if (root->data == q)
    {
        rightLevel = level;
        return;
    }

    checkCousins(root->left, p, q, leftFinal, rightFinal, leftLevel, rightLevel, level + 1);
    checkCousins(root->right, p, q, leftFinal, rightFinal, leftLevel, rightLevel, level + 1);

    if (leftLevel != -1 && leftFinal == NULL)
        leftFinal = root;

    if (rightLevel != -1 && rightFinal == NULL)
        rightFinal = root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    int p, q;
    cin >> p >> q;

    BinaryTreeNode<int> *leftFinal = NULL;
    BinaryTreeNode<int> *rightFinal = NULL;

    int leftLevel = -1;
    int rightLevel = -1;

    checkCousins(root, p, q, leftFinal, rightFinal, leftLevel, rightLevel, 0);

    if (leftLevel == rightLevel && leftFinal != rightFinal)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}