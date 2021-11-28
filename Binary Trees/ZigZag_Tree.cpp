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

vector<vector<BinaryTreeNode<int> *>> printBinaryTree(BinaryTreeNode<int> *root)
{
    vector<vector<BinaryTreeNode<int> *>> arr;

    if (root == NULL)
        return arr;

    queue<BinaryTreeNode<int> *> q;

    q.push(root);
    q.push(NULL);

    vector<BinaryTreeNode<int> *> smallArr;

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front == NULL)
        {
            if (!q.empty())
                q.push(NULL);
            arr.push_back(smallArr);
            smallArr = {};
        }
        else
        {
            smallArr.push_back(front);

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }
    }

    return arr;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    vector<vector<BinaryTreeNode<int> *>> arr = printBinaryTree(root);

    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j]->data << " ";
            }
        }
        else
        {
            for (int j = arr[i].size() - 1; j >= 0; j--)
            {
                cout << arr[i][j]->data << " ";
            }
        }
        cout << endl;
    }

    return 0;
}