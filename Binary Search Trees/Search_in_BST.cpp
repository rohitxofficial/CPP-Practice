#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

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

bool findX(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;
    else if (root->data > x)
        return findX(root->left, x);
    else
        return findX(root->right, x);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    int x;
    cin >> x;

    if (findX(root, x))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    delete root;

    return 0;
}