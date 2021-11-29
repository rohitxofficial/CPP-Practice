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

void pairSum(BinaryTreeNode<int> *root, vector<int> &nums)
{
    if (root == NULL)
        return;

    nums.push_back(root->data);

    pairSum(root->left, nums);
    pairSum(root->right, nums);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int n;
    cin >> n;

    vector<int> nums;

    pairSum(root, nums);

    sort(nums.begin(), nums.end());

    int p1 = 0;
    int p2 = nums.size() - 1;

    while (p1 < p2)
    {
        int sum = nums[p1] + nums[p2];

        if (sum == n)
        {
            cout << nums[p1] << " " << nums[p2] << endl;
            p1++;
            p2--;
        }
        else if (sum < n)
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }

    return 0;
}