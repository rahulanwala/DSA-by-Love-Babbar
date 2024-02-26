#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        // memory free
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // non-empty list
        // assuming element is present in list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found - curr representing element wala node

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int getlength(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }

    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

/*
void split(Node *&head, Node *&head1, Node *&head2)
{
    int len = getlength(head);
    Node *temp = head;
    int d = (len / 2) - 1;
    int d2 = (len / 2) - 1;

    cout<<d<<endl;
    while (d--)
    {
        temp = temp->next;
        cout<<temp->data<<endl;
    }
    head1 = head;
    cout<<head1->data<<endl;
    head2 = temp->next;
    cout<<head2->data<<endl;
    temp->next = head;

    Node *temp2 = head2;
    while (d2--)
    {
        temp2 = temp2->next;
        cout<<temp2->data<<endl;
    }
    temp2->next = head2;

}*/

int main()
{
    Node *tail = NULL;

    // empty list me insert kr rhe hai
    insertNode(tail, 10, 1);
    insertNode(tail, 12, 2);
    insertNode(tail, 15, 3);
    insertNode(tail, 12, 4);
    insertNode(tail, 12, 5);
    insertNode(tail, 12, 6);
    print(tail);

    // Node *head1 = NULL;
    // Node *head2 = NULL;

    // split(tail, head1, head2);
    // print(head1);
    // print(head2);
    return 0;
}