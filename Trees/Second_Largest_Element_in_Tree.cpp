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

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    TreeNode<int> *largest = NULL;
    TreeNode<int> *secondLargest = NULL;

    queue<TreeNode<int> *> q;

    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();

        if (largest == NULL)
        {
            largest = front;
        }
        else if (secondLargest == NULL)
        {
            if (front->data > largest->data)
            {
                secondLargest = largest;
                largest = front;
            }
            else
            {
                secondLargest = front;
            }
        }
        else
        {
            if (front->data > largest->data && front->data > secondLargest->data)
            {
                secondLargest = largest;
                largest = front;
            }
            else if (front->data > secondLargest->data)
            {
                secondLargest = front;
            }
        }

        for (int i = 0; i < front->children.size(); i++)
        {
            q.push(front->children[i]);
        }
    }

    return secondLargest;
}

int main()
{
    TreeNode<int> *root = takeInput();

    TreeNode<int> *ans = secondLargest(root);

    cout << ans->data << endl;

    return 0;
}