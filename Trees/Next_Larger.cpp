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

TreeNode<int> *nextLarger(TreeNode<int> *root, int x)
{
    TreeNode<int> *ans = NULL;

    if (root->data > x)
        ans = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = nextLarger(root->children[i], x);

        if (smallAns != NULL)
        {
            if (ans == NULL)
            {
                ans = smallAns;
            }
            else
            {
                if (smallAns->data < ans->data)
                    ans = smallAns;
            }
        }
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInput();
    int x;
    cin >> x;

    TreeNode<int> *ans = nextLarger(root, x);

    if (ans == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << ans->data << endl;
    }
    return 0;
}