#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int data;
    cin >> data;

    queue<BinaryTreeNode<int> *> q;

    BinaryTreeNode<int> *root = NULL;

    if (data != -1)
    {
        root = new BinaryTreeNode<int>(data);
        q.push(root);
    }

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        int leftData, rightData;

        cin >> leftData >> rightData;

        BinaryTreeNode<int> *left = NULL, *right = NULL;

        if (leftData != -1)
        {
            left = new BinaryTreeNode<int>(leftData);
            q.push(left);
        }
        if (rightData != -1)
        {
            right = new BinaryTreeNode<int>(rightData);
            q.push(right);
        }

        front->left = left;
        front->right = right;
    }

    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    int s;
    cin >> s;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    BinaryTreeNode<int> *temp = root;

    while (temp != NULL)
    {
        s1.push(temp);
        temp = temp->left;
    }

    temp = root;

    while (temp != NULL)
    {
        s2.push(temp);
        temp = temp->right;
    }

    while (s1.top()->data < s2.top()->data)
    {
        int num1 = s1.top()->data;
        int num2 = s2.top()->data;
        if (num1 + num2 == s)
        {
            cout << min(num1, num2) << " " << max(num1, num2) << endl;

            BinaryTreeNode<int> *top1 = s1.top();
            BinaryTreeNode<int> *top2 = s2.top();

            s1.pop();
            s2.pop();

            if (top1->right != NULL)
            {
                top1 = top1->right;
                while (top1 != NULL)
                {
                    s1.push(top1);
                    top1 = top1->left;
                }
            }

            if (top2->left != NULL)
            {
                top2 = top2->left;
                while (top2 != NULL)
                {
                    s2.push(top2);
                    top2 = top2->right;
                }
            }
        }
        else if (num1 + num2 < s)
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();

            if (top->right != NULL)
            {
                top = top->right;
                while (top != NULL)
                {
                    s1.push(top);
                    top = top->left;
                }
            }
        }

        else
        {
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();

            if (top->left != NULL)
            {
                top = top->left;
                while (top != NULL)
                {
                    s2.push(top);
                    top = top->right;
                }
            }
        }
    }

    return 0;
}