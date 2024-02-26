#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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

Node *reverse(Node *&temp)
{
    Node *prev = NULL;
    Node *curr = temp;
    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node *add(Node *&first, Node *&second)
{
    int sum = 0;
    int carry = 0;
    Node *anshead = NULL;
    Node *anstail = NULL;

    while (first != NULL && second != NULL)
    {
        sum = carry + first->data + second->data;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);

        carry = sum / 10;
        first = first->next;
        second = second->next;
    }

    while (first != NULL)
    {
        sum = carry + first->data;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);

        carry = sum / 10;
        first = first->next;
    }

    while (second != NULL)
    {
        sum = carry + second->data;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);

        carry = sum / 10;
        second = second->next;
    }
    while (carry != 0)
    {
        sum = carry;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);
 
        carry = sum / 10;
    }

    return anshead;
}

Node *optimizedAdd(Node *&first, Node *&second)
{
    int sum = 0;
    int carry = 0;
    Node *anshead = NULL;
    Node *anstail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
            first = first->next;
        }

        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
            second = second->next;
        }

        sum = carry + val1 + val2;
        int digit = sum % 10;

        insertAtTail(anshead, anstail, digit);

        carry = sum / 10;
    }

    return anshead;
}

Node *sumOfTwoLL(Node *&first, Node *&second)
{
    // step-1 : reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step-2 : add 2 LL
    // Node *ans = add(first, second);
    Node *ans = optimizedAdd(first, second);

    // step-3 : reverse ans
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node *head1 = new Node(3);
    Node *tail1 = head1;
    insertAtTail(head1, tail1, 4);

    Node *head2 = new Node(2);
    Node *tail2 = head2;
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 0);

    print(head1);
    print(head2);

    Node *ans = sumOfTwoLL(head1, head2);
    print(ans);
    return 0;
}