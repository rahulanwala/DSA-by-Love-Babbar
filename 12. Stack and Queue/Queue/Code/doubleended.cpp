#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbkQzRklGZVJOcDUzWHNhYXhsdnItUkNRVlZnQXxBQ3Jtc0ttV0FMLWMwNVA2NjU0YXhYVlczNmgtUWt2RGFleUw0LWlFRkpIYUgtdDQtM2FuUnA0WHBzUXhTRmQ0SlhTbXRoamFTOWZBVmwtcFh4MWxPUXFqUDYwMXplRGM2QUpYZzhkUUdQSDJsOHR0UEVPLXpkbw&q=https%3A%2F%2Fbit.ly%2F3JoEvmF&v=W7uB9-TKfTg

class Dqueue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
            return true;
        else
            return false;
    }

public:
    Dqueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear = size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
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

    int popRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }

        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }
};

int main()
{
    Dqueue dq(5);

    dq.pushFront(3);
    dq.pushRear(5);
    dq.pushFront(4);
    dq.pushRear(6);
    dq.pushFront(7);
    dq.pushRear(8);

    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;

    return 0;
}