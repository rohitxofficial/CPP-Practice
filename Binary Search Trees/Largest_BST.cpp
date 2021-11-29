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

struct heightBST
{
    bool isBST;
    int height;
    int max;
    int min;
};

heightBST largestBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {true, 0, INT_MIN, INT_MAX};

    heightBST left = largestBST(root->left);
    heightBST right = largestBST(root->right);

    if (left.isBST && right.isBST)
    {
        if (left.max < root->data && right.min > root->data)
            return {true, max(left.height, right.height) + 1, max(root->data, max(left.max, right.max)), min(root->data, min(left.min, right.min))};
        else
            return {false, max(left.height, right.height), max(root->data, max(left.max, right.max)), min(root->data, min(left.min, right.min))};
    }
    else
    {
        return {false, max(left.height, right.height), max(root->data, max(left.max, right.max)), min(root->data, min(left.min, right.min))};
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    heightBST ans = largestBST(root);

    cout << ans.height << endl;

    return 0;
}