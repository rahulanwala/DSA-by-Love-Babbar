#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

int main()
{
    int arr[4] = {4, 3, 2, 6};
    int n = 4;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long cost = 0;
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    cout << cost << endl;

    return 0;
}