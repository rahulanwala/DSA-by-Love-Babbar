#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3H1lKov

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

Node *reverseIte(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
}

void solve(Node *&head, Node *&curr, Node *&prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    solve(head, forward, curr);
    curr->next = prev;
}

Node *reverseRec(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    solve(head, curr, prev);
    return head;
}

Node *reverseRec1(Node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node*chotahead = reverseRec1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

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
        // New node create
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

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 7);
    print(head);

    // Node *ans = reverseIte(head);
    // print(ans);

    // reverseRec(head);
    // print(head);

    Node *recans1 = reverseRec1(head);
    print(recans1);
    return 0;
}