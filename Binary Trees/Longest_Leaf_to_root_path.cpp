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

vector<int> longestLeafRootPath(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        vector<int> output;
        return output;
    }

    vector<int> left = longestLeafRootPath(root->left);
    vector<int> right = longestLeafRootPath(root->right);

    if (left.size() > right.size())
    {
        left.push_back(root->data);
        return left;
    }
    else
    {
        right.push_back(root->data);
        return right;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    vector<int> ans = longestLeafRootPath(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}