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

int largestNode(TreeNode<int> *root)
{
    int largest = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        int temp_largest = largestNode(root->children[i]);

        if (temp_largest > largest)
            largest = temp_largest;
    }

    return largest;
}

int main()
{
    TreeNode<int> *root = takeInput();

    cout << largestNode(root) << endl;

    return 0;
}