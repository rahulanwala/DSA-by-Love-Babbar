#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

queue<int> approach1(queue<int> q, int n)
{
    queue<int> newq;

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        newq.push(val);
    }

    while (!newq.empty())
    {
        int val = newq.front();
        newq.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

queue<int> approach2(queue<int> q, int n)
{
    stack<int> st;

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();

        st.push(val);
    }

    while (!st.empty())
    {
        int val = st.top();
        st.pop();

        q.push(val);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();

        q.push(val);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();

        st.push(val);
    }

    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main()
{
    int a[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = 10;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        q.push(a[i]);
    }

    // approach - 1
    q = approach1(q, n);
    queue<int> q2 = q;

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // approach - 2
    q = approach2(q2, n);

    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    return 0;
}