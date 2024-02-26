#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0

class Queue
{
private:
    int size;
    int fr;
    int rear;
    int *arr;

public:
    Queue()
    {
        int size = 100001;
        arr = new int[size];
        fr = 0;
        rear = 0;
    }

    bool push(int data)
    {
        if (rear < size)
        {
            arr[rear] = data;
            rear++;
        }
    }

    int pop()
    {
        int ans = 0;
        if (fr == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            ans = arr[fr];
            arr[fr] = -1;
            fr++;

            if (fr == rear)
            {
                fr = 0;
                rear = 0;
            }
        }
        return ans;
    }

    bool isEmpty()
    {
        if (fr == rear)
            return true;
        else
            return false;
    }

    int front()
    {
        if (fr == rear)
            return -1;
        else
            return arr[fr];
    }
};

int main()
{

    /*
    //create a queue
    queue<int> q;
    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;
    q.push(13);
    cout << "front of q is: " << q.front() << endl;
    cout << "size of queue is : " << q.size() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "size of queue is : " << q.size() << endl;
    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }
    return 0;
}
    */

    Queue q;
    q.push(2);
    q.push(3);
    q.push(5);

    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    cout << q.pop() << endl;
    cout << q.front();

    return 0;
}