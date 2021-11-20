#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;

    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

    BinaryTreeNode<int> *insertData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (node->data > data)
        {
            node->left = insertData(data, node->left);
        }
        else
        {
            node->right = insertData(data, node->right);
        }
        return node;
    }

    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (node->data > data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else if (node->data < data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;

                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }

    void PrintTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        queue<BinaryTreeNode<int> *> pendingNodes;
        pendingNodes.push(root);

        while (pendingNodes.size() != 0)
        {
            BinaryTreeNode<int> *curr = pendingNodes.front();
            pendingNodes.pop();

            cout << curr->data << ": ";

            if (curr->left != NULL)
            {
                pendingNodes.push(curr->left);
                cout << "L -> " << curr->left->data << " ";
            }

            if (curr->right != NULL)
            {
                pendingNodes.push(curr->right);
                cout << "R -> " << curr->right->data << " ";
            }

            cout << endl;
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
        this->root = deleteData(data, this->root);
    }

    void insertData(int data)
    {
        this->root = insertData(data, this->root);
    }

    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void PrintTree()
    {
        PrintTree(root);
    }
};