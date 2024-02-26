#include<bits/stdc++.h>
using namespace std;
// https://bit.ly/3rjMQC5

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

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    print(head);

    Node *ans = removeduplicate(head);
    print(ans);
    return 0;
}