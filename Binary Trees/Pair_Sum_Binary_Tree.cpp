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

int secondPair(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
    {
        int temp = root->data;
        root->data = INT_MIN;
        return temp;
    }

    int left = secondPair(root->left, k);
    int right = secondPair(root->right, k);

    if (left != -1)
        return left;
    else if (right != -1)
        return right;
    else
        return -1;
}

void pairSum(BinaryTreeNode<int> *root, BinaryTreeNode<int> *curr, int k)
{
    if (curr == NULL)
    {
        return;
    }

    int firstData = curr->data;

    int secondData = secondPair(root, k - firstData);

    if (secondData != -1 && firstData != secondData)
    {
        int smaller = (firstData < secondData) ? firstData : secondData;
        int greater = (firstData < secondData) ? secondData : firstData;
        cout << smaller << " " << greater << endl;
    }

    pairSum(root, curr->left, k);
    pairSum(root, curr->right, k);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int n;
    cin >> n;

    pairSum(root, root, n);

    return 0;
}