#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        next = NULL;
        this->data = data;
    }

    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

node *mergeSortedLinkedList(vector<node *> arr)
{
    priority_queue<node *, vector<node *>, compare> minHeap;
    int k = arr.size();

    if (k == 0)
    {
        return NULL;
    }

    for (int i = 0; i < k; i++)
    {
        if (arr[i])
        {
            minHeap.push(arr[i]);
        }
    }

    node *head = NULL;
    node *tail = NULL;

    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();
        minHeap.pop();

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

        if (tail->next != NULL)
        {
            minHeap.push(tail->next);
        }
    }

    return head;
}

int main()
{

    return 0;
}