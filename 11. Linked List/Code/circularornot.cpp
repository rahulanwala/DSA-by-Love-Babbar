#include <bits/stdc++.h>
using namespace std;

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

bool circular(Node *&head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    Node *tail = NULL;

    // empty list me insert kr rhe hai
    insertNode(tail, 10, 12);
    insertNode(tail, 12, 15);
    insertNode(tail, 15, 18);
    insertNode(tail, 12, 16);
    print(tail);

    if (circular(tail) == 1)
        cout << "This is circular linked list." << endl;
    else
        cout << "This is not a circular linked list." << endl;
    return 0;
}