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

bool identical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1->data != root2->data)
    {
        return false;
    }

    if (root1->children.size() != root2->children.size())
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        if (root1->children[i]->data != root2->children[i]->data)
        {
            return false;
        }
    }

    bool final = true;

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool ans = identical(root1->children[i], root2->children[i]);

        if (ans == false)
        {
            final = false;
        }
    }

    return final;
}

int main()
{
    TreeNode<int> *root1 = takeInput();
    TreeNode<int> *root2 = takeInput();

    if (identical(root1, root2))
        cout << "true";
    else
        cout << "false";

    return 0;
}