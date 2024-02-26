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

node *solve(int in[], int pre[], int n, int &index, int inorderStart, int inorderEnd, map<int, int> nodeToIndex)
{
    if ((index >= n) || (inorderStart > inorderEnd))
    {
        return NULL;
    }

    int element = pre[index++];
    node *root = new node(element);
    int position = nodeToIndex[element];

    root->left = solve(in, pre, n, index, inorderStart, position - 1, nodeToIndex);
    root->right = solve(in, pre, n, index, position + 1, inorderEnd, nodeToIndex);

    return root;
}

node *consturctor(int in[], int pre[], int n, map<int, int> nodeToIndex)
{
    int index = 0;
    return solve(in, pre, n, index, 0, n - 1, nodeToIndex);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int n;
    cin >> n;

    int *in = new int[n];
    int *pre = new int[n];

    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    map<int, int> nodeToIndex;
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
    node *root = consturctor(in, pre, n, nodeToIndex);
    // levelOrderTraversal(root);
    postorder(root);
    return 0;
}

// Write code
/*
class Solution
{
public:
    int find(int n, int s, int e, int in[])
    {
        for (int i = s; i < e; i++)
        {
            if (in[i] == n)
                return i;
        }
    }
    void solve(Node *&root, int in[], int pre[], int s, int e, int &index, int n)

    {
        if (s > e || index >= n)
            return;
        root = new Node(pre[index]);
        int pos = find(pre[index], s, e, in);
        index = index + 1;
        solve(root->left, in, pre, s, pos - 1, index, n);
        solve(root->right, in, pre, pos + 1, e, index, n);
        return;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        Node *root;
        int i = 0;
        solve(root, in, pre, 0, n - 1, i, n);
        return root;
    }
};
*/

