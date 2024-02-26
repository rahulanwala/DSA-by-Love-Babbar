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

void deleteNode(Node *&tail, int element)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // non-empty list
        // assuming element is present in list

        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // One node linked list
        if (curr = prev)
        {
            tail = NULL;
        }
        
        // >=2 Node linked list
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;

    // empty list me insert kr rhe hai
    insertNode(tail, 10, 12);
    print(tail);

    insertNode(tail, 12, 15);
    print(tail);

    insertNode(tail, 15, 18);
    print(tail);

    insertNode(tail, 12, 16);
    print(tail);

    deleteNode(tail, 15);
    print(tail);
    return 0;
}