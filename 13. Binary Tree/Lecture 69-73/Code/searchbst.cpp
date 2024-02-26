#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878

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

node *insertIntoBST(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

bool searchInBSTRec(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    } 

    if (root->data == data)
    {
        return true;
    }

    if (root->data > data)
    {
        return searchInBSTRec(root->left, data);
    }
    else
    {
        return searchInBSTRec(root->right, data);
    }
}

bool searchInBSTIte(node *root, int data)
{
    node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }

        if (temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return false;
}

node *maxValue(node *root)
{
    node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

node *minValue(node *root)
{
    node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

node *deletion(node *root, int val)
{
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deletion(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletion(root->left, val);
        return root;
    }
    else
    {
        root->right = deletion(root->right, val);
        return root;
    }
}

int main()
{
    node *root = NULL;

    cout << "Enter the data for BST : " << endl;
    // 10 8 21 7 27 5 4 3 -1
    takeInput(root);

    cout << "Printing the BST : " << endl;
    levelOrderTraversal(root);

    int x;
    cout << "Enter the value of x : " << endl;
    cin >> x;

    if (searchInBSTRec(root, x) == 1)
    {
        cout << "Yes, " << x << " is present." << endl;
    }
    else
    {
        cout << x << " is not present." << endl;
    }

    if (searchInBSTIte(root, x) == 1)
    {
        cout << "Yes, " << x << " is present." << endl;
    }
    else
    {
        cout << x << " is not present." << endl;
    }

    cout << "Minimum value in BST = " << minValue(root)->data << endl;
    cout << "Maximum value in BST = " << maxValue(root)->data << endl;

    int val;
    cout << "Enter the value for deletion = " << endl;
    cin >> val;

    node *newRoot = deletion(root, val);
    cout << "Printing the BST : " << endl;
    levelOrderTraversal(newRoot);
    
    return 0;
}
