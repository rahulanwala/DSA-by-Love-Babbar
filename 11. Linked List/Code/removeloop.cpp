#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3rSdTDo

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

bool detectloop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "Starting point of cycle is = " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node *floyeddetectionloop(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

Node *getstart(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = floyeddetectionloop(head);

    if (fast == NULL)
    {
        return NULL;
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeloop(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startOfLoop = getstart(head);
    if (startOfLoop == NULL)
    {
        return;
    }
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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

    if (detectloop(tail) == 1)
        cout << "Loop present in this  linked list." << endl;
    else
        cout << "Loop not present in this  linked list." << endl;

    if (floyeddetectionloop(tail) != NULL)
        cout << "Loop present in this  linked list." << endl;
    else
        cout << "Loop not present in this  linked list." << endl;

    Node *ans = getstart(tail);
    cout << "Starting node is = " << ans->data << endl;

    // remove loop
    removeloop(tail);

    // Check again that loop is present or not
    if (detectloop(tail) == 1)
        cout << "Loop present in this  linked list." << endl;
    else
        cout << "Loop not present in this  linked list." << endl;
    return 0;
}