#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

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

pair<bool, int> isSumTree(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSumTree(root->left);
    pair<bool, int> right = isSumTree(root->right);

    bool isLeftSum = left.first;
    bool isRightSum = right.first;
    bool condn = (root->data == left.second + right.second);

    pair<bool, int> ans;
    if (isLeftSum && isRightSum && condn)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool solve(node *root)
{
    return isSumTree(root).first;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 1 3 5 -1 -1 4 6 -1 -1 -1 2 3 -1 -1 4 -1 -1

    cout << "isBalanced = " << solve(root) << endl;
    return 0;
}