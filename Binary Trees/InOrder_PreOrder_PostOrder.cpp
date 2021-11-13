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

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);

    postOrder(root->right);

    cout << root->data << " ";
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preOrder(root->left);

    preOrder(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    cout << "In-Order: " << endl;
    inOrder(root);
    cout << endl;

    cout << "Pre-Order: " << endl;
    preOrder(root);
    cout << endl;

    cout << "Post-Order: " << endl;
    postOrder(root);
    cout << endl;

    delete root;

    return 0;
}