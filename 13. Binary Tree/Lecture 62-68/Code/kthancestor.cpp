#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

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

node *solve(node *root, int &k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n)
    {
        return root;
    }

    node *leftAns = solve(root->left, k, n);
    node *rightAns = solve(root->right, k, n);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return rightAns;
    }

    return NULL;
}

int kthAncestor(node *root, int k, int n)
{
    node *ans = solve(root, k, n);

    if (ans == NULL || root->data == n)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1 

    int k = 2;
    int n = 4;
    cout << "Kthancestor = " << kthAncestor(root, k,n) << endl;
    return 0;
}