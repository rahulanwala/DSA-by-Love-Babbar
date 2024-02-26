#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3rfFdfV

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

Node *merge(Node *&head1, Node *&head2)
{
    Node *ans = new Node(0);
    Node *head = ans;
    Node *tail = ans;

    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            insertAtTail(head, tail, temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            insertAtTail(head, tail, temp1->data);
            temp1 = temp1->next;
        }
    }

    while (temp1 != NULL)
    {
        insertAtTail(head, tail, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        insertAtTail(head, tail, temp2->data);
        temp2 = temp2->next;
    }

    // dummy(0) node ko htane ke liye
    ans = ans->next;
    return ans;
}

Node *solve(Node *&first, Node *&second)
{
    // if only one element is present in first list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next; 

    while (curr2 != NULL && next1 != NULL)
    {
        if ((next1->data >= curr2->data) && (curr1->data <= curr2->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *method2(Node *&first, Node *&second)
{
    if (first == NULL)
        return second;
    else if (second == NULL)
        return first;

    if (first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
}

int main()
{
    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 5);

    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 6);

    print(head1);
    print(head2);

    Node *ans = merge(head1, head2);
    print(ans);

    Node *ans2 = method2(head1, head2);
    print(ans2);

    return 0;
}