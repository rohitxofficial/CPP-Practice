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

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<int> *> toPrint;

    toPrint.push(root);

    while (toPrint.size() != 0)
    {
        TreeNode<int> *front = toPrint.front();
        toPrint.pop();

        cout << front->data << " ";
        for (int i = 0; i < front->children.size(); i++)
        {
            toPrint.push(front->children[i]);
        }
    }
}

TreeNode<int> *takeInput()
{
    queue<TreeNode<int> *> pendingNodes;

    int data;
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;

            TreeNode<int> *childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

void replace(TreeNode<int> *root, int level)
{
    root->data = level;

    for (int i = 0; i < root->children.size(); i++)
    {
        replace(root->children[i], level + 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();

    int level = 0;
    replace(root, level);

    printTree(root);

    return 0;
}