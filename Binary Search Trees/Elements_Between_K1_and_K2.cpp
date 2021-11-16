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

void elementsBetween(BinaryTreeNode<int> *root, int x, int y)
{
    if (root == NULL)
        return;

    if (root->data >= x)
        elementsBetween(root->left, x, y);

    if (root->data >= x && root->data <= y)
        cout << root->data << " ";

    if (root->data <= y)
        elementsBetween(root->right, x, y);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();

    int x, y;

    cin >> x >> y;

    elementsBetween(root, x, y);

    delete root;

    return 0;
}