#include <iostream>
#include <queue>
#include <climits>
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

bool checkBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data > max || root->data < min)
        return false;

    bool output = checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);

    return output;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    if (checkBST(root, INT_MIN, INT_MAX))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    delete root;

    return 0;
}