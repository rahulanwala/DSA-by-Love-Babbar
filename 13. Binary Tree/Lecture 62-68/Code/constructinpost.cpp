#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

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

node *solve(int in[], int post[], int n, int &index, int inorderStart, int inorderEnd, map<int, int> nodeToIndex)
{
    if ((index <0) || (inorderStart > inorderEnd))
    {
        return NULL;
    }

    int element = post[index--];
    node *root = new node(element);
    int position = nodeToIndex[element];

    root->right = solve(in, post, n, index, position + 1, inorderEnd, nodeToIndex);
    root->left = solve(in, post, n, index, inorderStart, position - 1, nodeToIndex);

    return root;
} 

node *consturctor(int in[], int post[], int n, map<int, int> nodeToIndex)
{
    int index = n-1;
    return solve(in, post, n, index, 0, n -1, nodeToIndex);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin >> n;

    int *in = new int[n];
    int *post = new int[n];

    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];

    map<int, int> nodeToIndex;
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
    node *root = consturctor(in, post, n, nodeToIndex);
    // levelOrderTraversal(root);
    preorder(root);
    return 0;
}