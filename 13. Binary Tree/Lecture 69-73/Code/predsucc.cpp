#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

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

pair<int, int> predecessorSuccessor(node *root, int k)
{
    node *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != k)
    {
        if (temp->data > k) 
        {
            succ = temp->data; 
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    node *left = temp->left;
    node *right = temp->right;

    while (left)
    {
        pred = left->data;
        left = left->right;
    }

    while (right)
    {
        succ = right->data;
        right = right->left;
    }

    return {pred, succ};
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // 5 4 2 -1 3 -1 -1 -1 8 6 -1 7 -1 -1 10 -1 -1 8(k)

    int k;
    cin >> k;

    pair<int, int> ans = predecessorSuccessor(root, k);
    cout << "Predcessor = " << ans.first << " "
         << " Successor = " << ans.second << endl;
    return 0;
}