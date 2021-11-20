#include <iostream>
#include <queue>
#include <climits>
#include "BinaryTreeNode.h"
using namespace std;

struct CheckBST_Pair
{
    int max;
    int min;
    bool ans;
};

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

CheckBST_Pair checkBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        CheckBST_Pair output = {INT_MIN, INT_MAX, true};
        return output;
    }

    CheckBST_Pair left = checkBST(root->left);
    CheckBST_Pair right = checkBST(root->right);

    int minimum = min(root->data, min(left.min, right.min));
    int maximum = max(root->data, max(right.max, left.max));

    if (left.max < root->data && right.min > root->data && left.ans && right.ans)
    {
        CheckBST_Pair output = {maximum, minimum, true};
        return output;
    }
    else
    {
        CheckBST_Pair output = {maximum, minimum, false};
        return output;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    if (checkBST(root).ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    delete root;

    return 0;
}