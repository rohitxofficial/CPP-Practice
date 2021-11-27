#include <bits/stdc++.h>
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

struct BalancedCheckPair
{
    bool valid;
    int depth;
};

BalancedCheckPair isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {true, 0};

    BalancedCheckPair left = isBalanced(root->left);
    BalancedCheckPair right = isBalanced(root->right);

    int newDepth = max(left.depth, right.depth) + 1;

    bool newValid = left.valid && right.valid && (abs(left.depth - right.depth) <= 1);

    return {newValid, newDepth};
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    if (isBalanced(root).valid)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}