#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3tRF3ga

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

int middleElement(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    Node *newtemp = head;
    int d = len / 2;
    while (d--)
    {
        newtemp = newtemp->next;
    }
    int middle = newtemp->data;

    return middle;
}

int Optimizedsolve(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }

    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow->data;
}

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 9);
    print(head);

    // int middle = middleElement(head);
    // cout << "Middle element of this linked list is = " << middle << endl;

    int middle1 = Optimizedsolve(head);
    cout << "Middle element of this linked list is = " << middle1 << endl;

    return 0;
}