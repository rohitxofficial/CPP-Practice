#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *constructBST(int arr[], int st, int en)
{
    if (st > en)
    {
        return NULL;
    }

    int mid = (st + en) / 2;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);

    BinaryTreeNode<int> *left = constructBST(arr, st, mid - 1);
    BinaryTreeNode<int> *right = constructBST(arr, mid + 1, en);

    root->left = left;
    root->right = right;

    return root;
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BinaryTreeNode<int> *root = constructBST(arr, 0, n - 1);

    preOrder(root);

    return 0;
}