#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

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

vector<int> mergeArray(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i++];
    }

    while (j < b.size())
    {
        ans[k++] = b[j++];
    }

    return ans;
}

node *mergeTwoBST(node *bst1, node *bst2)
{
    // store inorder
    vector<int> a;
    inorder(bst1, a);
    vector<int> b;
    inorder(bst2, b);

    // merge two sorted inorder
    vector<int> merge = mergeArray(a, b);

    // inorder to bst
    int s = 0, e = merge.size() - 1;

    return inorderToBST(s, e, merge);
}

// *******Optimized Approach*******

void convertIntoSortedDLL(node *root, node *&head)
{
    if (root == NULL)
    {
        return;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head)
    {
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left, head);
}

node *mergeLinkedList(node *head1, node *head2)
{
    node *head = NULL;
    node *tail = NULL;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNode(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

node *sortedLLToBST(node *head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    node *left = sortedLLToBST(head, n / 2);

    node *root = head; 
    root->left = left;

    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

node *mergeBST(node *root1, node *root2)
{
    // 1. Finding both sorted linked list
    node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // 2. merge both linked list
    node *head = mergeLinkedList(head1, head2);
    int n = countNode(head);

    // 3. sortedlinkedlist to BST
    return sortedLLToBST(head, n);
}

int main()
{
    node *root1 = NULL;
    root1 = buildTree(root1);
    node *root2 = NULL;
    root2 = buildTree(root2);
    // 4 2 7 -1 3 -1 -1 -1 -1 5 1 7 -1 -1 -1 -1

    levelOrderTraversal(root1);
    levelOrderTraversal(root2);

    node *ansRoot = mergeTwoBST(root1, root2);

    levelOrderTraversal(ansRoot);

    return 0;
}
