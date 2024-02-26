#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

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

int getlength(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
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
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // at first position
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // at last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // at middle position
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    (temp->next)->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
}

void deleteNode(Node *&head, int position)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        // memory free krna
        delete temp;
    }
    // deleting middle or last node
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << "Length is : " << getlength(head) << endl;

    insertAtHead(head, tail, 12);
    print(head);

    insertAtHead(head, tail, 15);
    print(head);

    insertAtTail(head, tail, 12);
    print(head);

    insertAtTail(head, tail, 15);
    print(head);

    insertAtPosition(head, tail, 3, 20);
    print(head);

    deleteNode(head, 4);
    print(head);
    return 0;
}