#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

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

void flatten(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *current;
    node *pre;

    current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            pre = current->left;
            while (pre->right)
            {
                pre = pre->right;
                pre->right = current->right;
                current->right = current->left;
            }
            current = current->right;
        }
        current = root;
        while (current = NULL)
        {
            current->left = NULL;
            current = current->right;
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    flatten(root);
    // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1

    return 0;
} 