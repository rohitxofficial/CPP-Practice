#include <iostream>
#include <queue>
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

struct findDiameterPair
{
    int max = 0;
    int height = 0;
};

findDiameterPair findDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {0, 0};

    findDiameterPair left = findDiameter(root->left);

    findDiameterPair right = findDiameter(root->right);

    int maximum = max(left.height + right.height, max(left.max, right.max));

    findDiameterPair ans = {maximum, max(right.height, left.height) + 1};

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    findDiameterPair ans = findDiameter(root);

    cout << ans.max << endl;

    return 0;
}