#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqay1zVFI3SDJGalBEVll5X21yajBYN2lFUXVyd3xBQ3Jtc0traHdmUVlVMDFGUnYwQV9sZWNicVMwMjcxTDJiWlZZWVVNWHdzNHc5LXA2ZmpacVBqVFNSdURmNnNBODM2RWpVam5peElzLUNpR1RtOTVrZnNhRXVvUVhUWkNxWERfa3VaODA5MkRHM3pTS091TnlYNA&q=https%3A%2F%2Fbit.ly%2F3GsXWsz&v=rM5EEA_rbNY

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        // memory free
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for Node with data " << value << endl;
    }
};

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge 2 sorted Linked List
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into 2 halvs, after finding mid
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = merge(left, right);

    return result;
}

int main()
{
    Node *head = new Node(3);
    Node *tail = head;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 8);
    print(head);

    Node *ans = mergeSort(head);
    print(ans);

    return 0;
}
