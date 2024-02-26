#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

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

vector<int> diagonalTraversal(node *root)
{
    vector<int> ans;
    queue<node *> q;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();

        while (frontNode)
        {
            if (frontNode->left)
                q.push(frontNode->left);
                
            ans.push_back(frontNode->data);
            frontNode = frontNode->right;
        }
    }

    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 5 2 -1 -1 -1

    vector<int> ans = diagonalTraversal(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}