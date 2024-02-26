#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0

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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool isBST(node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        return (left && right);
    }

    return false;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 4 2 1 -1 -1 5 -1 -1 5 -1 -1

    if (isBST(root, INT_MIN, INT_MAX) == 1)
    {
        cout << "Yes, it is valid." << endl;
    }
    else
    {
        cout << "It is not valid." << endl;
    }

    return 0;
}
