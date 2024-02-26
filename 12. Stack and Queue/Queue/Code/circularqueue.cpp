#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbFBoLUJvbXRSSzBpX210ZEZBX3pKSjhYeXhJd3xBQ3Jtc0tuallmdHptb2syc2dLODhRZDhGbVBPajhabklyT3JSMTUtUVBqNkpDaGpmWF9ZdGxyQW95eEFPWVRZN0xfcDUtWFNhLU1MblUtQXNpVG9OZzdOSnkzYTdFRU1zTU5WTVVoWVFaUGFURGVta1Z3YTZSSQ&q=https%3A%2F%2Fbit.ly%2F34xocVZ&v=W7uB9-TKfTg

class CircularQueue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool push(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear)==(front-1)%(size-1))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1)
        {
            // first element
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; 
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }

        return true;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            // single element
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }

    bool empty(){
        if(front==-1)return true;
        else return false;
    }
};

int main()
{
    CircularQueue q(5);

    cout<<q.push(2)<<endl;
    cout<<q.push(3)<<endl;
    cout<<q.push(4)<<endl;
    cout<<q.push(5)<<endl;

    while(q.empty()){
        cout<<q.pop()<<endl;
    }
    return 0;
}