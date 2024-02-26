#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

int main()
{
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 4;

    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << "K-th smallest element = " << pq.top() << endl;
    return 0;
}