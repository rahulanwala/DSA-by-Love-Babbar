#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqblZPcm1OdGVRQXZYRDREQWxmdXdaR0RtMW1wd3xBQ3Jtc0tsQURqT0djcjlXcDFCcmM2Y2g4VHZXWTVNNk8yR1Z3N3doRzViSlBlX0lfbUQ4aElYWFk0YjRKbnAyUVZ4VDFiZUIxRGdHemZYT2pJN3dXTlJmT3g0QTYzX3NNYl92dFF5WG1MSGVaWWVOTGE4U2JnTQ&q=https%3A%2F%2Fbit.ly%2F3GoASv6&v=rM5EEA_rbNY
 
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

int main(){
    
    return 0;
} 