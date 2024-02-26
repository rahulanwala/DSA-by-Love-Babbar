#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/

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

Node *getmid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
 
bool isPalindrome(Node *&head)
{
    if (head->next == NULL)
    {
        return true;
    }

    Node *middle = getmid(head);
    Node *temp = middle->next;
    middle->next = reverse(temp);

    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    print(head);

    if (isPalindrome(head))
    {
        cout << "Linked list is a Palindrome." << endl;
    }
    else
    {
        cout << "Linked list is not a Palindrome." << endl;
    }
    return 0;
}