#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
        cout << "Memory is free for node with data " << value << endl;
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

Node *copyList(Node *&head)
{
    // step 1: create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step2 : create a map
    unordered_map<Node *, Node *> oldToNewNode;
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

Node *optimizedSol(Node *&head)
{
    // step 1 : create a clone Node
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    { 
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2: clone node add in-between original node
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step 3:random pointer copy
    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;
        else
            temp->next->random = temp->random;
        temp = temp->next->next;
    }

    // step 4:revert changes done in step 2
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
    }

    // step 5:return ans
    return cloneHead;
}

int main()
{
    Node *head = new Node(3);
    Node *tail = head;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 9);
    print(head);

    Node *ans = copyList(head);
    print(ans);

    Node *ans2 = optimizedSol(head);
    print(ans2);

    // here we are not giving input with random node that's why ans is different due to step 3

    return 0;
}