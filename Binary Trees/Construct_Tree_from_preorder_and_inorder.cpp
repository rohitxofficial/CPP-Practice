#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *curr = pendingNodes.front();
        pendingNodes.pop();

        cout << curr->data << ": ";

        if (curr->left != NULL)
        {
            pendingNodes.push(curr->left);
            cout << "L -> " << curr->left->data << " ";
        }

        if (curr->right != NULL)
        {
            pendingNodes.push(curr->right);
            cout << "R -> " << curr->right->data << " ";
        }

        cout << endl;
    }
}

BinaryTreeNode<int> *construct(int preOrder[], int inOrder[], int preOrderStart, int preOrderEnd, int inOrderStart, int inOrderEnd)
{
    if (inOrderStart > inOrderEnd)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrder[preOrderStart]);

    int rootInOrderIndex = -1;
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (root->data == inOrder[i])
        {
            rootInOrderIndex = i;
            break;
        }
    }

    int leftInOrderStart = inOrderStart;
    int leftInOrderEnd = rootInOrderIndex - 1;
    int leftPreOrderStart = preOrderStart + 1;
    int leftPreOrderEnd = leftInOrderEnd - leftInOrderStart + leftPreOrderStart;

    int rightPreOrderStart = leftPreOrderEnd + 1;
    int rightPreOrderEnd = preOrderEnd;
    int rightInOrderStart = rootInOrderIndex + 1;
    int rightInOrderEnd = inOrderEnd;

    BinaryTreeNode<int> *leftChild = construct(preOrder, inOrder, leftPreOrderStart, leftPreOrderEnd, leftInOrderStart, leftInOrderEnd);
    BinaryTreeNode<int> *rightChild = construct(preOrder, inOrder, rightPreOrderStart, rightPreOrderEnd, rightInOrderStart, rightInOrderEnd);

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int main()
{
    int n;
    cin >> n;
    int *preOrder = new int[n];
    int *inOrder = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    BinaryTreeNode<int> *root = construct(preOrder, inOrder, 0, n - 1, 0, n - 1);

    printBinaryTree(root);

    delete root;

    return 0;
}
