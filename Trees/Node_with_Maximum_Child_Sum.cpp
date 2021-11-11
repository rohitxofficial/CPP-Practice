#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

struct TreeNode_and_Sum
{
    TreeNode<int> *address = NULL;
    int sum = 0;
};

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

TreeNode_and_Sum maximumSum(TreeNode<int> *root)
{
    TreeNode_and_Sum finalAns;
    finalAns.address = root;
    finalAns.sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        finalAns.sum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode_and_Sum max = maximumSum(root->children[i]);

        if (max.sum > finalAns.sum)
        {
            finalAns.address = max.address;
            finalAns.sum = max.sum;
        }
    }

    return finalAns;
}

int main()
{
    TreeNode<int> *root = takeInput();

    TreeNode_and_Sum finalAns = maximumSum(root);

    cout << finalAns.address->data << "@" << finalAns.sum << endl;

    return 0;
}