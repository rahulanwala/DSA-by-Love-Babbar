#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problem-details/count-leaf-nodes_893055

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

void inorder(node *root, int &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, count);

    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    inorder(root->right, count);
}

int noOfLeafNodes(node *root)
{
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    cout << noOfLeafNodes(root) << endl;
}