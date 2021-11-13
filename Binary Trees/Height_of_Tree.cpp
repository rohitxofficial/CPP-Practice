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

int heightTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1;

    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);

    ans += (leftHeight > rightHeight) ? leftHeight : rightHeight;

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    cout << heightTree(root) << endl;

    delete root;

    return 0;
}