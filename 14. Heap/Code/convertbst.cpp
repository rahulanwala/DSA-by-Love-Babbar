#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/convert-bst-min-heap/

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

void inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void BSTToMinHeap(node *&root, vector<int> ans, int &index)
{
    if (root == NULL)
    {
        return;
    }

    root->data = ans[index++];

    BSTToMinHeap(root->left, ans, index);
    BSTToMinHeap(root->right, ans, index);
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

    vector<int> ans;
    inorder(root, ans);

    int index = 0;
    BSTToMinHeap(root, ans, index);
    levelOrderTraversal(root);

    return 0;
}