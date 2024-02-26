#include <bits/stdc++.h>
using namespace std;

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

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// inorder, preorder, postorder using iterative approach
void solveite(node *root)
{
    stack<pair<node *, int>> st;
    st.push({root, 1});

    vector<int> pre;
    vector<int> in;
    vector<int> post;

    while (!st.empty())
    {
        node *new_node = st.top().first;
        int state = st.top().second;

        if (state == 1)
        {
            pre.push_back(new_node->data);
            st.top().second = state + 1;
            if (new_node->left)
            {
                st.push({new_node->left, 1});
            }
        }
        else if (state == 2)
        {
            in.push_back(new_node->data);
            st.top().second = state + 1;
            if (new_node->right)
            {
                st.push({new_node->right, 1});
            }
        }
        else
        {
            post.push_back(new_node->data);
            st.pop();
        }
    }

    cout << "Inorder using iterative : ";
    for (auto i : in)
    {
        cout << i << " ";
    }

    cout << endl
         << "Preorder using iterative : ";
    for (auto i : pre)
    {
        cout << i << " ";
    }

    cout << endl
         << "Postorder using iterative : ";
    for (auto i : post)
    {
        cout << i << " ";
    }
    cout << endl;
}

void inorder_ite(node *root)
{
    stack<node *> st;
    node *curr = root;
    vector<int> ans;

    while (1)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        if (curr == NULL && !st.empty())
        {
            node *top = st.top();
            st.pop();

            ans.push_back(top->data);

            curr = top->right;
        }

        if (curr == NULL && st.empty())
        {
            break;
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{

    node *root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // /*
    // creating a Tree
    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order traversal output " << endl;
    // levelOrderTraversal(root);

    cout << endl
         << "preorder traversal is:  ";
    preorder(root);

    cout << endl
         << "postorder traversal is:  ";
    postorder(root);
    cout << endl;

    solveite(root);

    cout << "inorder traversal is (iterative):  ";
    inorder_ite(root);

    // */

    return 0;
}