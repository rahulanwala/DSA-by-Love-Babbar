#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

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

void solve(node *root, int &ans, int &k)
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
            k--;
            if (k == 0)
            {
                k = INT_MAX;
                ans = current->data;
            }
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
                k--;
                if (k == 0)
                {
                    k = INT_MAX;
                    ans = current->data;
                }
                current = current->right;
            }
        }
    }
}

int kthSmallest(node *root, int &k)
{
    int ans = -1;
    solve(root, ans, k);

    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    int k;
    cin >> k;

    cout << "k-th smallest element = " << kthSmallest(root, k) << endl;
    // 5 4 2 -1 3 -1 -1 -1 8 6 -1 7 -1 -1 10 -1 -1 3(k)

    return 0;
}