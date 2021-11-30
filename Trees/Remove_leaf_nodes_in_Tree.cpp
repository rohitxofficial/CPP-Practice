#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<int> *> toPrint;

    toPrint.push(root);
    toPrint.push(NULL);

    while (toPrint.size() != 0)
    {
        TreeNode<int> *front = toPrint.front();
        toPrint.pop();

        if (front == NULL)
        {
            cout << endl;

            if (!toPrint.empty())
                toPrint.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            for (int i = 0; i < front->children.size(); i++)
            {
                toPrint.push(front->children[i]);
            }
        }
    }
}

TreeNode<int> *takeInput()
{
    queue<TreeNode<int> *> pendingNodes;

    int data;
    cout << "Enter root data: ";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter num of children of " << front->data << ": ";
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;

            TreeNode<int> *childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

TreeNode<int> *removeLeaf(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;

    if (root->children.size() == 0)
        return NULL;

    for (int i = 0; i < root->children.size(); i++)
    {
        root->children[i] = removeLeaf(root->children[i]);
    }

    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        if (root->children[i] == NULL)
            root->children.erase(root->children.begin() + i);
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInput();

    root = removeLeaf(root);

    printTree(root);

    return 0;
}