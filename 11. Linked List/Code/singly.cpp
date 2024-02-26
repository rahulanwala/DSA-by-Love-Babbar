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
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

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
        // New node create
        Node *temp = new Node(d);
        temp->next = head;
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
        // New node create
        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // inserting at start
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

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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

void deleteNode(Node *&head, int position)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free krna
        temp->next = NULL;
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    /*
    Node node1(3);

    cout << node1.data << endl;
    cout << node1.next << endl;

    Node *node2 = new Node(2);

    cout << node2->data << endl;
    cout << node2->next << endl;
    return 0;

    */

    // Created a new node
    Node *node1 = new Node(10);
    // Node *node1 = NULL;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head, tail, 12);
    print(head);

    insertAtHead(head, tail, 15);
    print(head);

    insertAtTail(head, tail, 12);
    print(head);

    insertAtTail(head, tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 11);
    print(head);

    deleteNode(head, 2);
    print(head);
    return 0;
}