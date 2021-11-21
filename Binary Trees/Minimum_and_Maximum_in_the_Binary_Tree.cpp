#include <iostream>
#include <queue>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
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

struct maxAndMinPair
{
    int max;
    int min;
};

maxAndMinPair maxAndMin(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {INT_MIN, INT_MAX};

    maxAndMinPair left = maxAndMin(root->left);
    maxAndMinPair right = maxAndMin(root->right);

    return {max(left.max, max(right.max, root->data)), min(left.min, min(right.min, root->data))};
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    maxAndMinPair ans = maxAndMin(root);

    cout << ans.min << " " << ans.max << endl;

    return 0;
}