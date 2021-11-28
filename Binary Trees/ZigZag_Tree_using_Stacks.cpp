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

void printZigZagTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    stack<BinaryTreeNode<int> *> s1, s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        if (s1.empty())
        {
            // work on s2
            while (!s2.empty())
            {
                cout << s2.top()->data << " ";

                if (s2.top()->right != NULL)
                    s1.push(s2.top()->right);

                if (s2.top()->left != NULL)
                    s1.push(s2.top()->left);

                s2.pop();
            }
            cout << endl;
        }
        else
        {
            // work on s1
            while (!s1.empty())
            {
                cout << s1.top()->data << " ";

                if (s1.top()->left != NULL)
                    s2.push(s1.top()->left);

                if (s1.top()->right != NULL)
                    s2.push(s1.top()->right);

                s1.pop();
            }
            cout << endl;
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    printZigZagTree(root);

    return 0;
}