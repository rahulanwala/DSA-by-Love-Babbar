#include <bits/stdc++.h>
using namespace std;
//  https://bit.ly/3uaGRRU

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

Node *removeduplicate(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }

    map<int, bool> visited;

    Node *curr = head;
    Node*prev = NULL;

    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            Node *next_next = curr->next;
            prev->next = curr->next;
            Node *ToDelete = curr;
            delete (ToDelete);
            curr = next_next;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    print(head);

    Node *ans = removeduplicate(head);
    print(ans);
    return 0;
}
