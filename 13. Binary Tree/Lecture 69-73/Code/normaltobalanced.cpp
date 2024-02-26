#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

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

node *inorderToBST(int s, int e, vector<int> &ans)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(ans[mid]);
    root->left = inorderToBST(s, mid - 1, ans);
    root->right = inorderToBST(mid + 1, e, ans);

    return root;
}

node *normalToBalanced(node *root)
{
    vector<int> ans;
    inorder(root, ans);

    return inorderToBST(0, ans.size() - 1, ans);
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 10 8 4 2 -1 -1 -1 -1 12 -1 16 -1 20 -1 -1

    node *newRoot = normalToBalanced(root);

    levelOrderTraversal(newRoot);

    return 0;
}
