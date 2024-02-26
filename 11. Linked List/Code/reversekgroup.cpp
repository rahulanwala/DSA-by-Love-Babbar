#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3r1rCIP

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

Node *reverse(Node *&head,int k)
{
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node *forward = NULL;
    Node *prev = NULL;
    Node *curr = head;
    int count=0;

    while(curr!=NULL && count<k){
        forward = curr->next;
        curr->next = prev;
        prev=curr;
        curr = forward;
        count++; 
    } 

    if(forward!=NULL){
        head->next = reverse(forward,k);
    }
    return prev;
}

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 13);
    insertAtTail(head, tail, 15);
    print(head);

    Node*ans = reverse(head,3);
    print(ans);
    return 0;
}