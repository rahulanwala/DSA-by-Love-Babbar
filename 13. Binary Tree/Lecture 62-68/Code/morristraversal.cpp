#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    { 
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    } 
};

node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void morrisTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *current, *pre;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    morrisTraversal(root);
    // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1

    return 0;
}