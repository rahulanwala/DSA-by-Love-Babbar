#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3s3fAOu

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

Node *sortList(Node *&head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else if (temp->data == 2)
            count2++;

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL) 
    {
        if (count0 != 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 != 0)
        {
            temp->data = 1;
            count1--;
        }
        else if (count2 != 0)
        {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

Node *sortwithoutrep(Node *&head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            insertAtTail(zeroHead, zeroTail, curr->data);
        }
        else if (curr->data == 1)
        {
            insertAtTail(oneHead, oneTail, curr->data);
        }
        else if (curr->data == 2)
        {
            insertAtTail(twoHead, twoTail, curr->data);
        }

        curr = curr->next;
    }

    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    print(head);

    Node *ans = sortList(head);
    print(ans);

    Node *ans2 = sortwithoutrep(head);
    print(ans2);

    return 0;
}